/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:19:42 by gguedes           #+#    #+#             */
/*   Updated: 2022/07/21 10:34:31 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_case(int error_value)
{
	if (error_value == 1)
		perror("Error value = 1: Invalid number of argvs");
	else if (error_value == 2)
		perror("Error value = 2: Failed to initialize pipe");
	else if (error_value == 3)
		perror("Error value = 3: Failed to fork");
	else if (error_value == 4)
		perror("Error value = 4: Invalid fd");
	else if (error_value == 5)
		perror("Error value = 5: Error executing command");
	return (errno);
}
