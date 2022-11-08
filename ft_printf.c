/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:44:59 by mamedeir          #+#    #+#             */
/*   Updated: 2022/11/09 00:08:59 by mamedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flags(char flag, va_list args)
{
	int	len;

	len = 0;
	if (flag == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (flag == 's')
		len += ft_printstring(va_arg(args, char *));
	else if (flag == 'p')
		len += ft_printptr(va_arg(args, unsigned long));
	else if (flag == 'd' || flag == 'i')
		len += ft_printdecimal(va_arg(args, int));
	else if (flag == 'u')
		len += ft_printunsig(va_arg(args, unsigned int));
	else if (flag == 'x' || flag == 'X')
		len += ft_printhex(va_arg(args, unsigned int), flag);
	else if (flag == '%')
		len += ft_printchar('%');
	else
		return (write(1, "%", 1) + ft_printchar(flag));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '%')
			len += write(1, &(str[i]), 1);
		else
		{
			i++;
			len += ft_print_flags(str[i], args);
		}
		i++;
	}
	va_end(args);
	return (len);
}
