/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char_string_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/22 13:54:07 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/22 13:54:09 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	spacing_zeros(int *spacing, char filler)
{
	(*spacing)--;
	return (write(1, &filler, 1));
}

int	print_char_perc(t_flags *type, va_list arg)
{
	int	spacing;
	int	length;
	int	argument;

	length = 0;
	spacing = type->width;
	while (spacing > 1 && !type->minus && !type->zero)
		length += spacing_zeros(&spacing, ' ');
	while (spacing > 1 && !type->minus && type->zero)
		length += spacing_zeros(&spacing, '0');
	if (type->type == '%')
		length += write(1, "%", 1);
	else
	{
		argument = va_arg(arg, int);
		length += write(1, &argument, 1);
	}
	while (spacing > 1 && type->minus)
		length += spacing_zeros(&spacing, ' ');
	return (length);
}

static int	print_null(t_flags *type)
{
	int	length;
	int	printed;
	int	spacing;

	printed = 0;
	length = ft_strlen("(null)");
	spacing = type->width - length;
	while (type->precision >= 0 && type->precision < length && type->width > 0)
		printed += spacing_zeros(&type->width, ' ');
	if (type->precision >= 0 && type->precision < length)
		return (printed);
	while (!type->minus && spacing > 0)
		printed += spacing_zeros(&spacing, ' ');
	printed += write(1, "(null)", length);
	while (type->minus && spacing > 0)
		printed += spacing_zeros(&spacing, ' ');
	return (printed);
}

static int	print_str(t_flags *type, char *str)
{
	int	length;
	int	printed;

	printed = 0;
	length = ft_strlen(str);
	if (type->precision >=0 && type->precision < length)
		length = type->precision;
	while (!type->minus && type->width > length)
		printed += spacing_zeros(&type->width, ' ');
	printed += write(1, str, length);
	while (type->minus && type->width > length)
		printed += spacing_zeros(&type->width, ' ');
	return (printed);
}

int	print_string(t_flags *type, va_list arg)
{
	char	*str;
	int		length;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (print_null(type));
	return (print_str(type, str));
}
