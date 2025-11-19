/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pointer_hex.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/19 14:50:20 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/19 15:32:07 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_write_hex(unsigned long addr)
{
	char	*hex_values;

	hex_values = "0123456789abcdef";
	
	return (0);
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
