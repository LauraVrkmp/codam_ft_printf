/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pointer_hex_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/22 13:54:24 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/22 13:54:27 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	fill_str(char **str, char format, unsigned long long addr, \
unsigned int number)
{
	char	*hex_values;
	int		i;

	i = 19;
	if (format == 'x' || format == 'p')
		hex_values = "0123456789abcdef";
	else if (format == 'X')
		hex_values = "0123456789ABCDEF";
	if (format == 'x' || format == 'X')
	{
		while (number > 0)
		{
			(*str)[i--] = hex_values[number % 16];
			number /= 16;
		}
	}
	else if (format == 'p')
	{
		while (addr > 0)
		{
			(*str)[i--] = hex_values[addr % 16];
			addr /= 16;
		}
	}
	return (i);
}

static int	convert_write_hex(unsigned long long addr, unsigned int number, \
char format)
{
	char	*str;
	int		length;
	int		i;

	length = 0;
	str = malloc(sizeof(char) * 21);
	if (str == NULL)
		return (0);
	str[20] = '\0';
	i = fill_str(&str, format, addr, number);
	i++;
	while (str[i])
		length += write(1, &str[i++], 1);
	free(str);
	return (length);
}

int	print_pointer(t_flags *type, va_list arg)
{
	void				*ptr;
	unsigned long long	addr;
	int					length;

	length = 0;
	ptr = va_arg(arg, void *);
	if (ptr == NULL)
	{
		length += write(1, "(nil)", ft_strlen("(nil)"));
		return (length);
	}
	addr = (unsigned long)ptr;
	length += write(1, "0x", 2);
	length += convert_write_hex(addr, 0, 'p');
	return (length);
}

int	print_hex(t_flags *type, va_list arg)
{
	unsigned int	num;
	int				length;

	length = 0;
	num = va_arg(arg, unsigned int);
	if (num == 0)
		length += write(1, "0", 1);
	else
		length += convert_write_hex(0, num, type->type);
	return (length);
}
