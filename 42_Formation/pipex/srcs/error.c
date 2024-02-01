/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:47:01 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/31 19:35:29 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, int status, char *error)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	ft_printf("pipex %s: %s\n", str, error);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	exit (status);
}

void	free_matrix(char ***matrix)
{
	int	y;

	y = 0;
	while (matrix[0][y])
		free(matrix[0][y++]);
	free(matrix[0]);
}

void	free_and_close(int *pipefd, char **cmd, char *cmd_path)
{
	ft_close_pipefd(pipefd);
	free(cmd_path);
	free_matrix(&cmd);
}

void	ft_close_pipefd(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
}
