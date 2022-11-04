/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:44:59 by mamedeir          #+#    #+#             */
/*   Updated: 2022/11/04 16:49:27 by mamedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flags(char flag, va_list args)
{
	int	len;

	len = 0;
	if (flag == 'c')
		len += ft_printchar(va_arg(args, int));
	if (flag == 's')
		len += ft_printstr(va_arg(args, char *));
	if (flag == 'p')
		len += ft_printptr(va_arg(args, unsigned long));
	if (flag == 'd' || flag == 'i')
		len += ft_printdecimal(va_arg(args, int));
	if (flag == 'u')
		len += ft_printunsig(va_arg(args, unsigned int));
	if (flag == 'x' || flag == 'X')
		len += ft_printhex(va_arg(args, unsigned int), flag);
	if (flag == '%')
		len += printchar('%');
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
