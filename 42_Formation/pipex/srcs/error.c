/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:47:01 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/20 01:54:06 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_error_cmd()
{

}

void	free_matrix(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y])
		free(matrix[y++]);
}
