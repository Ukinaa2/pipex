/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:06:04 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/20 10:14:01 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*dest;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	slen = ft_strlen(s + start);
	if (len > slen)
		dest = malloc((slen + 1) * sizeof(*s));
	else
		dest = malloc((len + 1) * sizeof(*s));
	if (!dest)
		return (0);
	i = 0;
	while (s[i + start] && i < len)
	{
		dest[i] = (char)s[i + start];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
