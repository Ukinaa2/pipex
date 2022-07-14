/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:22:25 by gguedes           #+#    #+#             */
/*   Updated: 2022/07/14 12:15:59 by gguedes          ###   ########.fr       */
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
	while (ft_strncmp(environ[i], "PATH=", 5))
		i++;
	path = ft_split(&environ[i][5], ':');
	i = 0;
	cmd = ft_strjoin("/", cmd);
	i = 0;
	while (path[i])
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
	int			fd[2];
	char		*path;
	char		**cmd;
	extern char	**environ;

	if (argc != 5)
		return (1);
	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		fd[0] = open(argv[1], O_RDONLY);
		dup2(fd[0], STDIN_FILENO);
		cmd = ft_split(argv[2], ' ');
		path = find_command_path(cmd[0], environ);
		execve(path, cmd, environ);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		fd[1] = open(argv[4], O_WRONLY | O_CREAT);
		dup2(fd[1], STDOUT_FILENO);
		cmd = ft_split(argv[3], ' ');
		path = find_command_path(cmd[0], environ);
		execve(path, cmd, environ);
	}
	return (0);
}
