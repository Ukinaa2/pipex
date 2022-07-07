/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:22:25 by gguedes           #+#    #+#             */
/*   Updated: 2022/07/07 12:39:25 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		bytes_read;
	char	*buffer;

	printf("argc: %i\n", argc);
	i = 1;
	while (i < argc)
	{
		printf("argv[%i]: %s\n", i, argv[i]);
		i++;
	}
	fd = open(argv[1], O_RDONLY);
	buffer = malloc(sizeof(char) * (10));
	bytes_read = read(fd, buffer, 10);
	buffer[bytes_read] = '\0';
	close(fd);
	printf("%s\n", buffer);
	write(1, argv[2], strlen(argv[2]));
	printf("\n");
	return (0);
}
