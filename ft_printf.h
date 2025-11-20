/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 05:52:00 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/20 19:27:26 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

char	*ft_itoa(int signednum, unsigned int unsignednum, int item);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		print_hex(char format, va_list arg);
int		print_number(char format, va_list arg);
int		print_pointer(va_list arg);