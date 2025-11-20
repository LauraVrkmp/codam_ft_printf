/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 05:51:22 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/20 20:54:14 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_char_perc(char format, va_list arg)
{
	int	argument;

	if (format == '%')
		write(1, "%", 1);
	else
	{
		argument = va_arg(arg, int);
		write(1, &argument, 1);
	}
	return (1);
}

static int	print_string(va_list arg)
{
	char	*str;
	int		length;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		length = ft_strlen("(null)");
		write(1, "(null)", length);
		return (length);
	}
	length = ft_strlen(str);
	write(1, str, length);
	return (length);
}

static int	print_id(char format, va_list args)
{
	int	format_length;

	if (format == 'c' || format == '%')
		format_length = print_char_perc(format, args);
	else if (format == 's')
		format_length = print_string(args);
	else if (format == 'p')
		format_length = print_pointer(args);
	else if (format == 'd' || format == 'i' || format == 'u')
		format_length = print_number(format, args);
	else if (format == 'x' || format == 'X')
		format_length = print_hex(format, args);
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

/* int	main(void)
{
	int	length;

	length = printf(" %p %p \n", 0, 0);
	printf("%d\n", length);
	return (0);
} */

/* int	main(void)
{
	int	length;

	length = ft_printf("Testing %x\n", LONG_MAX);
	printf("%d\n", length);
	length = printf("Testing %x\n", LONG_MAX);
	printf("%d\n", length);
	length = ft_printf("Testing %X\n", LONG_MIN);
	printf("%d\n", length);
	length = printf("Testing %X\n", LONG_MIN);
	printf("%d\n", length);
	return (0);
} */
