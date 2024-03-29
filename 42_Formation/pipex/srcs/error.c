/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:47:01 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/05 13:44:30 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(t_pipex *pipex, char *str, char *error, int status)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	ft_printf("pipex %s: %s\n", str, error);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	ft_close_pipefd(pipex->pipefd);
	if (pipex)
		free_pipex(pipex);
	exit (status);
}

void	free_pipex(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->path)
		free_matrix(&pipex->path);
}

void	free_matrix(char ***matrix)
{
	int	y;

	y = 0;
	while (matrix[0][y])
		free(matrix[0][y++]);
	free(matrix[0]);
	matrix = 0;
}

void	ft_close_pipefd(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
}
