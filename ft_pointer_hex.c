/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pointer_hex.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/19 14:50:20 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/20 13:14:34 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_write_hex(unsigned long addr)
{
	char	*hex_values;
	char	str[17];
	int		length;
	int		i;

	length = 0;
	i = 16;
	str[i--] = '\0';
	hex_values = "0123456789abcdef";
	while (addr > 0)
	{
		str[i--] = hex_values[addr % 16];
		addr /= 16;
	}
	i++;
	while (str[i])
		length += write(1, &str[i++], 1);
	return (length);
}

int	print_pointer(va_list arg)
{
	void			*ptr;
	unsigned long	addr;
	int				length;

	length = 0;
	ptr = va_arg(arg, void *);
	addr = (unsigned long)ptr;
	length += write(1, "0x", 2);
	length += convert_write_hex(addr);
	return (length);
}
