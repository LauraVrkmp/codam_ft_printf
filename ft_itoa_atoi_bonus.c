/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_atoi_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/22 13:54:12 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/22 13:54:16 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_find_length_neg(long n, int *is_neg, int *length)
{
	if (n < 0)
	{
		*is_neg = 1;
		(*length)++;
	}
	if (n == 0)
		(*length)++;
	while (n)
	{
		n /= 10;
		(*length)++;
	}
}

static char	*ft_fill_string(long nb, char *string, int length, int is_neg)
{
	string[length] = '\0';
	if (nb == 0)
	{
		string[0] = '0';
		return (string);
	}
	while (length-- > 0)
	{
		string[length] = nb % 10 + '0';
		nb /= 10;
	}
	if (is_neg)
		string[0] = '-';
	return (string);
}

char	*ft_itoa(int signednum, unsigned int unsignednum, int item)
{
	int		is_neg;
	int		length;
	char	*string;
	long	nb;

	is_neg = 0;
	length = 0;
	if (item == 1)
		nb = signednum;
	else if (item == 2)
		nb = unsignednum;
	ft_find_length_neg(nb, &is_neg, &length);
	if (nb < 0)
		nb = -nb;
	string = malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);
	string = ft_fill_string(nb, string, length, is_neg);
	return (string);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
		if (!(*nptr >= '0' && *nptr <= '9'))
			return (0);
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

int	parse_width_prec(t_flags *type, const char *format)
{
	int	intlen;
	
	if (type->period)
	{
		type->precision = ft_atoi(format);
		intlen = ft_intlen(type->precision);
	}
	else
	{
		type->width = ft_atoi(format);
		intlen = ft_intlen(type->width);
	}
	return (intlen);
}
