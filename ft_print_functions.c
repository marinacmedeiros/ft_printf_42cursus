/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:11:29 by mamedeir          #+#    #+#             */
/*   Updated: 2022/11/01 15:53:05 by mamedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}
//%c

int	ft_print_string(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*str)
		count += write(1, &(*str++), 1);
	return (count);
}
//%s

int	ft_print_decimal(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		if (n == -2147483648)
		{
			count += write(1, "2147483648", 10);
			return (count);
		}
		n = -n;
	}
	c = (n % 10) + '0';
	if (n <= 9)
	{
		count += write(1, &c, 1);
		return (count);
	}
	count += ft_print_dec(n / 10);
	count += write(1, &c, 1);
	return (count);
}
//%d

unsigned int	print_percent_sign(void)
{
	return (write(1, "%", 1));
}
//% %
