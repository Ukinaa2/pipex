/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:09:34 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/09 19:54:12 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	chr;
	char	*cs;

	i = ft_strlen(s);
	chr = c;
	cs = (char *)s;
	while (i && cs[i] != chr)
		i--;
	if (cs[i] != chr)
		return (NULL);
	else
		return (cs + i);
}
