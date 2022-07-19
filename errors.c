/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:19:42 by gguedes           #+#    #+#             */
/*   Updated: 2022/07/19 13:17:34 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_case(int error_value)
{
	if (error_value == 1)
		perror("Invalid number of argvs");
	else if (error_value == 2)
		perror("Failed to initialize pipe");
	else if (error_value == 3)
		perror("Failed to fork");
	else if (error_value == 4)
		perror("Invalid fd");
	else if (error_value == 5)
		perror("Error executing command");
	return (error_value);
}
