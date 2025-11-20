/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_number.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/20 17:47:55 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/20 19:01:19 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printing_number(int signednum, unsigned int unsignednum, int item)
{
	char	*num_str;
	int		length;

	length = 0;
	if (item == 1)
		num_str = ft_itoa(signednum, 0, item);
	else if (item == 2)
		num_str = ft_itoa(0, unsignednum, item);
	if (num_str == NULL)
		return (0);
	length += write(1, num_str, ft_strlen(num_str));
	free(num_str);
	return (length);
}

int	print_number(char format, va_list arg)
{
	int				signednum;
	unsigned int	unsignednum;
	int				length;
	int				printed;

	printed = 0;
	if (format == 'd' || format == 'i')
	{
		signednum = va_arg(arg, int);
		printed += printing_number(signednum, 0, 1);
	}
	else if (format == 'u')
	{
		unsignednum = va_arg(arg, unsigned int);
		printed += printing_number(0, unsignednum, 2);
	}
	if (printed == 0)
		return (0);
	length = printed;
	return (length);
}
