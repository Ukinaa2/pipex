/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:51:02 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/17 12:01:45 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	i = 0;
	if (!s1)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	while (*s1)
	{
		str[i] = *(char *)s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *(char *)s2;
		i++;
		s2++;
	}
	str[i] = 0;
	return (str);
}
