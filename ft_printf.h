/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:12:08 by mamedeir          #+#    #+#             */
/*   Updated: 2022/11/04 16:49:49 by mamedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_printstring(char *str);
int		ft_printdecimal(int n);
int		ft_printunsig(unsigned int n);
int		ft_printhex(unsigned long n, char c);
int		ft_printptr(unsigned long ptr);
int		ft_printchar(int c);
char	*ft_strdup(const char *src);
int		ft_print_flags(char flag, va_list args);

#endif
