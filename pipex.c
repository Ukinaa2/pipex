/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:22:25 by gguedes           #+#    #+#             */
/*   Updated: 2022/07/11 15:53:55 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int			i;
	int			id;
	char		*tmp;
	char		**cmd1;
	char		**path;
	extern char	**environ;

	id = fork();
	if (id == -1)
		return (0);
	if (id == 0)
	{
		i = 0;
		while (ft_strncmp(environ[i], "PATH=", 5)) //find PATH variable in environ
			i++;
		path = ft_split(environ[i]+5, ':'); //create PATH matrix
		i = 0;
		while (path[i]) //adds / into all paths
		{
			tmp = ft_strjoin(path[i], "/");
			free(path[i]);
			path[i] = tmp;
			i++;
		}
		
		cmd1 = ft_split(argv[2], ' '); //split cmd1
		i = 0;
		while (path[i]) //add cmd1 into paths and check if it exists
		{
			tmp = ft_strjoin(path[i], cmd1[0]);
			free(path[i]);
			path[i] = tmp;
			if (!access(path[i], F_OK) && !access(path[i], R_OK))
				ft_printf("path encontrado: %s\n", path[i]);
			i++;
		}
	}
	else
	{
	}
	return (0);
}
