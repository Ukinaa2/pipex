/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:52:52 by gguedes           #+#    #+#             */
/*   Updated: 2022/07/21 11:22:29 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_subs(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s++)
	{
		if (*s == 34)
		{
			s = ft_strchr(s + 1, 34);
			i++;
		}
		else if (*s == 39)
		{
			s = ft_strchr(s + 1, 39);
			i++;
		}
		else if (*s != c && (*(s + 1) == c || *(s + 1) == '\0')
			&& *(s + 1) != 34 && *(s + 1) != 39)
		{
			while (*s == c && *s)
				s++;
			i++;
		}
	}
	return (i);
}

static unsigned int	start(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static size_t	calc_len(char const *s, char c)
{
	int	i;

	i = 0;
	if (s[i] == 34)
	{
		i++;
		while (s[i] != 34)
			i++;
	}
	else if (s[i] == 39)
	{
		i++;
		while (s[i] != 39)
			i++;
	}
	else
		while (s[i] && s[i] != c && s[i] != 34 && s[i] != 39)
			i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	len;
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
		s += start(s, c);
		len = calc_len(s, c);
		array[i] = ft_substr(s, 0, len);
		array[i] = ft_strtrim(array[i], "'\"");
		s += len;
		i++;
	}
	array[i] = 0;
	return (array);
}

/*int	main(void)
{
	int	i;
	char *s = "grep \"'\"";
	char **array;

	i = 0;
	printf("%s\n", s);
	array = ft_split(s, ' ');
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}*/
