/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:47:01 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/24 14:56:08 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int	ft_error(char *str, int fd)
{
	perror(str);
	return (EXIT_FAILURE);
}

// void	ft_error_cmd()
// {
// }

void	free_matrix(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y])
		free(matrix[y++]);
}

void	close_pipefd(int *pipefd)
{
	int	index;

	index = 0;
	while (pipefd[index])
		close(pipefd[index++]);
}
