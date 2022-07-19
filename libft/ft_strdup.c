/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:47:54 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/16 11:22:17 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		str_size;
	char	*dest;

	i = 0;
	str_size = ft_strlen(str);
	dest = (char *)malloc((str_size + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	while (i < str_size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
