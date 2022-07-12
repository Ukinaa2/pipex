/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:42:29 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/09 19:56:08 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	char	*cs;

	chr = c;
	cs = (char *)s;
	while (*cs && *cs != chr)
		cs++;
	if (*cs != chr)
		return (NULL);
	else
		return (cs);
}
