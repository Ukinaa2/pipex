/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:22:25 by gguedes           #+#    #+#             */
/*   Updated: 2022/07/12 15:32:28 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	*find_command_path(char *cmd, char **environ)
{
	int			i;
	char		*tmp;
	char		**path;

	i = 0;
	while (ft_strncmp(environ[i], "PATH=", 5)) //find PATH variable in environ
		i++;
	path = ft_split(&environ[i][5], ':'); //create PATH matrix
	i = 0;
	while (path[i]) //adds / into all paths
	{
		tmp = ft_strjoin(path[i], "/");
		free(path[i]);
		path[i] = tmp;
		i++;
	}
	i = 0;
	while (path[i]) //add cmd into paths and check if it exists
	{
		tmp = ft_strjoin(path[i], cmd);
		free(path[i]);
		path[i] = tmp;
		if (!access(path[i], F_OK | R_OK))
			return (path[i]);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int			pid;
	char		*path;
	char		**cmd;
	extern char	**environ;

	if (argc != 5)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		cmd = ft_split(argv[2], ' '); //split cmd
		path = find_command_path(cmd[0], environ);
		if (!path)
			return (0);
		printf("%s\n", path);
		execve(path, cmd, environ);
	}
	else
	{
	}
	return (0);
}
