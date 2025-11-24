/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pointer_hex_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/22 13:54:24 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/24 10:51:00 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	format_start_hex(t_flags *type, int hex_length, char *str, int i)
{
	int	length;

	length = 0;
	if (type->precision > hex_length)
		while (type->width > type->precision && !type->minus)
			length += spacing_zeros(&type->width, ' ');
	else if (!type->zero || (type->zero && type->period))
		while (type->width > (hex_length - (type->num_zero && type->period && \
type->precision <= 0)) && !type->minus)
			length += spacing_zeros(&type->width, ' ');
	if (type->type == 'p' || (type->type == 'x' && type->hash && str[i] != '0'))
		length += write(1, "0x", 2);
	if (type->type == 'X' && type->hash && str[i] != '0')
		length += write(1, "0X", 2);
	while (type->precision > hex_length)
		length += spacing_zeros(&type->precision, '0');
	while (type->width > hex_length && type->zero && !type->period)
		length += spacing_zeros(&type->width, '0');
	return (length);
}

static int	write_hex(t_flags *type, char *str, int i)
{
	int	hex_length;
	int	length;
	int	prec;

	prec = type->precision;
	hex_length = ft_strlen(str + i);
	if (type->type == 'p' || (type->hash && str[i] != '0'))
		hex_length += 2;
	length = format_start_hex(type, hex_length, str, i);
	while (str[i] && !(type->period && type->precision <= 0 && str[i] == '0' \
&& str[i + 1] == '\0'))
		length += write(1, &str[i++], 1);
	if (prec > hex_length)
		while (type->width > prec && type->minus)
			length += spacing_zeros(&type->width, ' ');
	else
		while (type->width > (hex_length - (type->num_zero && type->period && \
type->precision <= 0)) && type->minus)
			length += spacing_zeros(&type->width, ' ');
	return (length);
}

static int	length_hex(unsigned long long addr, unsigned int number, \
t_flags *type)
{
	char	*str;
	int		length;
	int		i;

	i = 20;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (-1);
	str[i--] = '\0';
	if (number == 0 && (type->type == 'x' || type->type == 'X'))
	{
		str[i] = '0';
		type->num_zero = 1;
	}
	else
		i = fill_str(&str, type->type, addr, number) + 1;
	length = write_hex(type, str, i);
	free(str);
	return (length);
}

int	print_pointer(t_flags *type, va_list arg)
{
	void				*ptr;
	unsigned long long	addr;
	int					length;
	int					nill_length;

	length = 0;
	ptr = va_arg(arg, void *);
	if (ptr == NULL)
	{
		nill_length = ft_strlen("(nil)");
		while (type->width > nill_length && !type->minus)
			length += spacing_zeros(&type->width, ' ');
		length += write(1, "(nil)", ft_strlen("(nil)"));
		while (type->width > nill_length && type->minus)
			length += spacing_zeros(&type->width, ' ');
		return (length);
	}
	addr = (unsigned long)ptr;
	length += length_hex(addr, 0, type);
	return (length);
}

int	print_hex(t_flags *type, va_list arg)
{
	unsigned int	num;
	int				length;

	num = va_arg(arg, unsigned int);
	length = length_hex(0, num, type);
	return (length);
}
