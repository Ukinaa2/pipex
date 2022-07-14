/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:22:25 by gguedes           #+#    #+#             */
/*   Updated: 2022/07/13 23:47:48 by gguedes          ###   ########.fr       */
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
	int			fd[2];
	int			fd1;
	int			pid;
	char		*path;
	char		**cmd;
	extern char	**environ;

	if (argc != 5)
		return (0);
	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		close(fd[0]);
		cmd = ft_split(argv[2], ' '); //split cmd
		path = find_command_path(cmd[0], environ);
		if (!path)
			return (1);
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 == -1)
			return (1);
		dup2(fd1, STDIN_FILENO);
		execve(path, cmd, environ);
	}
	else
	{
		waitpid(-1, NULL, 0);
		close(fd[1]);
		cmd = ft_split(argv[3], ' '); //split cmd
		path = find_command_path(cmd[0], environ);
		if (!path)
			return (1);
		fd1 = open(argv[5], O_WRONLY | O_CREAT, 0777);
		if (fd1 == -1)
			return (1);
		dup2(fd1, STDOUT_FILENO);
		execve(path, cmd, environ);
	}
	return (0);
}
