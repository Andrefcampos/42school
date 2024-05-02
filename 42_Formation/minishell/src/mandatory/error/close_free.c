/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 04:41:49 by andrefil          #+#    #+#             */
/*   Updated: 2024/05/02 00:49:16 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

int	close_fds(int *fd)
{
	if (*fd)
	{
		close(fd[0]);
		close(fd[1]);
		return (1);
	}
	return (0);
}

void	free_matrix(char **matrix)
{
	int	index;

	if (!*matrix || !matrix)
		return ;
	index = 0;
	while(matrix[index])
	{
		free(matrix[index]);
		index++;
	}
	free (matrix);
	matrix = NULL;
}

void	free_data(t_ast **ast_list, t_token **token_list)
{
	ast_lstclear(ast_list);
	token_lstclear(token_list);
	free (ast_list);
	free(token_list);
	*ast_list = NULL;
	*token_list = NULL;
}
