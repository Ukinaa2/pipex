/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:26:45 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/12 19:48:20 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

char	*ft_itoa(int n)
{
	unsigned int	un;
	int				size;
	char			*new_str;

	size = ft_count_size(n);
	new_str = (char *)malloc((size + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[size] = '\0';
	if (n < 0)
		un = -n;
	else
		un = n;
	while (size--)
	{
		new_str[size] = un % 10 + '0';
		un /= 10;
	}
	if (n < 0)
		new_str[0] = '-';
	return (new_str);
}
