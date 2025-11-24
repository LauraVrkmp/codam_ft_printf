/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_number_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/22 13:54:20 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/24 13:51:46 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	format_start_number(t_flags *type, int num_length)
{
	int	written;

	written = 0;
	if (type->precision >= num_length && type->period)
		while (type->width > (type->plus + type->space + type->precision + \
type->neg) && !type->minus)
			written += spacing_zeros(&type->width, ' ');
	else
		while (type->width > (num_length + type->plus + type->space) && \
(!type->zero || (type->zero && type->precision >= 0)) && !type->minus)
			written += spacing_zeros(&type->width, ' ');
	if (type->plus && !type->neg)
		written += write(1, "+", 1);
	if (type->space && !type->plus && !type->neg)
		written += write(1, " ", 1);
	if (type->neg)
		written += write(1, "-", 1);
	while (type->width > (num_length + type->plus + type->space) && \
type->zero && type->precision == -1 && !type->minus)
		written += spacing_zeros(&type->width, '0');
	while (type->precision > (num_length - type->neg + type->space + \
type->plus))
		written += spacing_zeros(&type->precision, '0');
	return (written);
}

static int	write_length(char *num_str, t_flags *type)
{
	int	num_length;
	int	written;
	int	prec;

	prec = type->precision;
	num_length = ft_strlen(num_str);
	written = format_start_number(type, num_length);
	if (type->neg)
		written += write(1, num_str + 1, ft_strlen(num_str) - 1);
	else
		written += write(1, num_str, ft_strlen(num_str));
	if (prec >= num_length)
		while (type->width > (prec + type->plus + type->space + type->neg) \
&& type->minus)
			written += spacing_zeros(&type->width, ' ');
	else
		while (type->width > (num_length + type->plus + type->space) \
&& type->minus)
			written += spacing_zeros(&type->width, ' ');
	return (written);
}

static int	printing_number(int signednum, unsigned int unsignednum, \
t_flags *type)
{
	char	*num_str;
	int		length;

	length = 0;
	if (signednum < 0)
		type->neg = 1;
	if (type->type == 'd' || type->type == 'i')
		num_str = ft_itoa(signednum, 0, type->type);
	else if (type->type == 'u')
		num_str = ft_itoa(0, unsignednum, type->type);
	if (num_str == NULL)
	{
		free(type);
		return (-1);
	}
	while (type->period && type->precision <= 0 && num_str[0] == '0' && \
type->width > 0)
		length += spacing_zeros(&type->width, ' ');
	if (!(type->period && type->precision <= 0 && num_str[0] == '0'))
		length = write_length(num_str, type);
	free(num_str);
	return (length);
}

int	print_number(t_flags *type, va_list arg)
{
	int				signednum;
	unsigned int	unsignednum;
	int				length;

	if (type->type == 'd' || type->type == 'i')
	{
		signednum = va_arg(arg, int);
		length = printing_number(signednum, 0, type);
	}
	else if (type->type == 'u')
	{
		unsignednum = va_arg(arg, unsigned int);
		length = printing_number(0, unsignednum, type);
	}
	return (length);
}
