/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/22 13:54:36 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/22 13:54:38 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int 	period;
	int		hash;
	int		space;
	int		plus;
	char	type;
	int		width;
	int		precision;
}	t_flags;

void	ft_bzero(void *s, size_t n);
size_t	ft_intlen(int n);
char	*ft_itoa(int signednum, unsigned int unsignednum, int item);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		parse_width_prec(t_flags *type, const char *format);
int		print_char_perc(t_flags *type, va_list arg);
int		print_hex(t_flags *type, va_list arg);
int		print_number(t_flags *type, va_list arg);
int		print_pointer(t_flags *type, va_list arg);
int		print_string(t_flags *type, va_list arg);