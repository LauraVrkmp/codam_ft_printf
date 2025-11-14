/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 05:51:22 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/14 06:09:07 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_id(char *format, va_list args)
{
	int	format_length;

	if (*format == 'c')
		format_length = print_char(args);
	else if (*format == '%')
	{
		write(1, '%', 1);
		format_length = 1;
	}
	return (format_length);	
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_count;

	char_count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			char_count += print_id(*format, args);
		}
		else
		{
			write(1, format, 1);
			char_count++;
		}
		format++;
	}
	va_end(args);
	return (char_count);
}