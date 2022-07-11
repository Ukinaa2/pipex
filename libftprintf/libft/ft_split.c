/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:52:52 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/09 18:42:33 by gguedes          ###   ########.fr       */
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
	char	*new_str;

	i = 0;
	j = 0;
	while (*s && *s == c)
		s++;
	while (s[i] && s[i] != c)
		i++;
	new_str = (char *)malloc((i + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (j < i)
	{
		new_str[j] = s[j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
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
		return (NULL);
	i = 0;
	n_subs = count_subs(s, c);
	array = (char **)malloc((n_subs + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (i < n_subs)
	{
		array[i] = create_subs(s, c);
		s = next_sub(s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
