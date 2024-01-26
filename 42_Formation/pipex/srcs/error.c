/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:47:01 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/25 20:12:44 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

void	free_matrix(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y])
		free(matrix[y++]);
}

void	ft_not_cmd(int *pipefd, int fd, char **cmd)
{
	close(pipefd[1]);
	close(pipefd[0]);
	close(fd);
	free_matrix(cmd);
	ft_error(ERR_CMD);
}
