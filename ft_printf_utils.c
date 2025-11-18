/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/18 13:01:42 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/18 13:02:42 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}
