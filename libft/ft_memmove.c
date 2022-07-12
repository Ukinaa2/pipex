/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:31:23 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/09 19:39:02 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	cdest = dest;
	csrc = (char *)src;
	if (cdest > csrc)
		while (n--)
			cdest[n] = csrc[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
