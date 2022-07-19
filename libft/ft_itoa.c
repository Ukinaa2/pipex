/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:26:45 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/16 18:44:07 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static int	create_str(unsigned int n, int i, char *str)
{
	while (i > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	unsigned int	un;

	i = digits(n);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	str[i--] = 0;
	if (n < 0)
	{
		str[0] = '-';
		un = -n;
		create_str(un, i, str);
	}
	else
		str[0] = (create_str(n, i, str) % 10) + '0';
	return (str);
}
