/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:22:25 by gguedes           #+#    #+#             */
/*   Updated: 2022/07/14 13:51:44 by gguedes          ###   ########.fr       */
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

int	call_execve(char *argv)
{
	char		*path;
	char		**cmd;
	extern char	**environ;

	cmd = ft_split(argv, ' ');
	path = find_command_path(cmd[0], environ);
	if (!path)
	{
		perror("cmd do not exits.");
		return (1);
	}
	return (execve(path, cmd, environ));
}

int	main(int argc, char **argv)
{
	int			pid;
	int			fd[2];

	if (argc != 5)
	{
		perror("invalid number of argv");
		return (1);
	}
	if (pipe(fd) == -1)
	{
		perror("error creating pipe");
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] == -1)
		{
			perror("cant open file");
			return (1);
		}
		dup2(fd[0], STDIN_FILENO);
		if (call_execve(argv[2]))
			return (1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		dup2(fd[1], STDOUT_FILENO);
		if (call_execve(argv[3]))
			return (1);
	}
	return (0);
}
