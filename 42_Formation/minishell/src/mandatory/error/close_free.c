/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 04:41:49 by andrefil          #+#    #+#             */
/*   Updated: 2024/05/02 23:30:01 by andrefil         ###   ########.fr       */
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
	if (ast_list)
	{
		ast_lstclear(ast_list);
		free (*ast_list);
		*ast_list = NULL;
	}
	if (token_list)
	{
		token_lstclear(token_list);
		free(*token_list);
		*token_list = NULL;
	}
}
