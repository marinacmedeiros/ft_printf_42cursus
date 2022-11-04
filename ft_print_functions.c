/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:11:29 by mamedeir          #+#    #+#             */
/*   Updated: 2022/11/04 17:17:01 by mamedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(char *str)
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

int	ft_printdecimal(int n)
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
	count += ft_printdecimal(n / 10);
	count += write(1, &c, 1);
	return (count);
}
//%d

int	ft_printunsig(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	c = (n % 10) + '0';
	if (n <= 9)
	{
		count += write(1, &c, 1);
		return (count);
	}
	count += ft_printunsig(n / 10);
	count += write(1, &c, 1);
	return (count);
}
//%u

int	ft_printhex(unsigned long n, char c)
{
	char	*hex;
	int		count;

	count = 0;
	if (c == 'x')
		hex = ft_strdup("0123456789abcdef");
	else
		hex = ft_strdup("0123456789ABCDEF");
	if (n < 16)
	{
		count += write(1, &hex[n % 16], 1);
		free(hex);
		return (count);
	}
	count += ft_printhex(n / 16, c);
	count += write(1, &hex[n % 16], 1);
	free(hex);
	return (count);
}
//%X %x

int	ft_printptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_printhex(ptr, 'x');
	return (count);
}
//%p
