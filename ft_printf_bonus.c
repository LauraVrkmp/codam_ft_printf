/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/22 13:54:32 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/22 13:54:33 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_id(t_flags *type, va_list args)
{
	int	format_length;

	if (type->type == 'c' || type->type == '%')
		format_length = print_char_perc(type, args);
	else if (type->type == 's')
		format_length = print_string(type, args);
	else if (type->type == 'p')
		format_length = print_pointer(type, args);
	else if (type->type == 'd' || type->type == 'i' || type->type == 'u')
		format_length = print_number(type, args);
	else if (type->type == 'x' || type->type == 'X')
		format_length = print_hex(type, args);
	return (format_length);
}

static void	specify_flags(t_flags *type, char format)
{
	if (format == '-')
		type->minus = 1;
	if (format == '0' && type->zero == 0)
		type->zero = 1;
	if (format == '.')
		type->period = 1;
	if (format == '#')
		type->hash = 1;
	if (format == ' ')
		type->space = 1;
	if (format == '+')
		type->plus = 1;
}

static int	find_type(char format)
{
	if (format == 'c' || format == 's' || format == 'p' || format == 'd' || format == 'i' \
	|| format == 'u' || format == 'x' || format == 'X' || format == '%')
		return (1);
	return (0);
}

static const char	*read_format(t_flags **type, const char *format)
{
	*type = malloc(sizeof(t_flags));
	if (*type == NULL)
		return (NULL);
	ft_bzero(*type, sizeof(t_flags));
	(*type)->precision = -1;
	(*type)->width = -1;
	while (*format)
	{
		specify_flags(*type, *format);
		if ((*format >= '1' && *format <= '9') || ((*type)->period && *format == '0'))
			format += parse_width_prec(*type, format) - 1;
		if (find_type(*format))
		{
			(*type)->type = *format;
			format++;
			return (format);
		}
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	*type;
	int		char_count;

	char_count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format = read_format(&type, format);
			if (type == NULL)
				return (-1);
			char_count += print_id(type, args);
			free(type);
		}
		else
			char_count += write(1, format++, 1);
	}
	va_end(args);
	return (char_count);
}

int	main(void)
{
	int	length;

	length = printf("a%10.9sa\n", "abcd");
	printf("%d\n", length);
	length = ft_printf("a%10.9sa\n", "abcd");
	printf("%d\n", length);
	return (0);
}

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
