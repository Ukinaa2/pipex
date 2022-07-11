/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:57:12 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/12 19:08:17 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_args(va_list args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		i += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
	{
		i += ft_putstr_fd("0x", 1);
		i += ft_puthex_fd(va_arg(args, unsigned long), "0123456789abcdef", 1);
	}
	else if (c == 'd' || c == 'i')
		i += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		i += ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		i += ft_puthex_fd(va_arg(args, unsigned int), "0123456789abcdef", 1);
	else if (c == 'X')
		i += ft_puthex_fd(va_arg(args, unsigned int), "0123456789ABCDEF", 1);
	else if (c == '%')
		i += ft_putchar_fd('%', 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += check_args(args, *str);
		}
		else
			i += ft_putchar_fd(*str, 1);
		str++;
	}
	return (i);
}
