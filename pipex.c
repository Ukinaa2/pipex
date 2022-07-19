/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:22:25 by gguedes           #+#    #+#             */
/*   Updated: 2022/07/19 13:35:54 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int pid, int fd[2], char **argv)
{
	if (pid == 0)
	{
		close(fd[0]);
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] == -1)
			return (-1);
	}
	else
	{
		close(fd[1]);
		fd[1] = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
		if (fd[1] == -1)
			return (-1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	return (0);
}

char	*find_command_path(char *cmd, char **envp)
{
	int		i;
	char	*tmp;
	char	**path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_split(&envp[i][5], ':');
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

int	call_execve(int pid, char **argv, char **envp)
{
	char	*path;
	char	**cmd;

	if (pid == 0)
		cmd = ft_split(argv[2], ' ');
	else
	{
		cmd = ft_split(argv[3], ' ');
		waitpid(pid, NULL, 0);
	}
	path = find_command_path(cmd[0], envp);
	if (!path)
		return (-1);
	if (execve(path, cmd, envp) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	fd[2];

	if (argc != 5)
		return (error_case(1));
	if (pipe(fd) == -1)
		return (error_case(2));
	pid = fork();
	if (pid == -1)
		return (error_case(3));
	if (pipex(pid, fd, argv) == -1)
		return (error_case(4));
	if (call_execve(pid, argv, envp) == -1)
		return (error_case(5));
	return (0);
}
