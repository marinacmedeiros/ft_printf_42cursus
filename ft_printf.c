/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:44:59 by mamedeir          #+#    #+#             */
/*   Updated: 2022/11/03 20:17:48 by mamedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_argument(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(ap, int));
	if (c == 's')
		count += ft_print_str(va_arg(ap, char *));
	if (c == 'p')
		count += ft_print_ptr(va_arg(ap, unsigned long));
	if (c == 'd' || c == 'i')
		count += ft_print_dec(va_arg(ap, int));
	if (c == 'u')
		count += ft_print_uns(va_arg(ap, unsigned int));
	if (c == 'x' || c == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), c);
	if (c == '%')
		count += print_percent_sign('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	
}
