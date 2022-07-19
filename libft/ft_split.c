/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:52:52 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/17 12:03:15 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_subs(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
			i++;
		s++;
	}
	return (i);
}

static char	*create_subs(char const *s, char c)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	j = 0;
	while (*s && *s == c)
		s++;
	while (s[i] && s[i] != c)
		i++;
	sub = (char *)malloc((i + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	while (j < i)
	{
		sub[j] = s[j];
		j++;
	}
	sub[j] = 0;
	return (sub);
}

static char const	*next_sub(char const *s, char c)
{
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
			return (s + 1);
		s++;
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		n_subs;
	char	**array;

	if (!s)
		return (0);
	i = 0;
	n_subs = count_subs(s, c);
	array = (char **)malloc((n_subs + 1) * sizeof(char *));
	if (!array)
		return (0);
	while (i < n_subs)
	{
		array[i] = create_subs(s, c);
		s = next_sub(s, c);
		i++;
	}
	array[i] = 0;
	return (array);
}
