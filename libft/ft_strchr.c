/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:42:29 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/18 13:35:20 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && (char)*s != (char)c)
		s++;
	if ((char)*s != (char)c)
		return (0);
	else
		return ((char *)s);
}
