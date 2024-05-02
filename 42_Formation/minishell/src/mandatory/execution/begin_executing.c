/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_executing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:53:23 by mavitori          #+#    #+#             */
/*   Updated: 2024/05/02 23:30:23 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	execute_operator(t_ast *operator)
{
	if (operator->ast_type == LESS)
		return (execute_redirect_input(operator));
	else if (operator->ast_type == GREAT)
		return (execute_redirect_output(operator));
	else if (operator->ast_type == DGREAT)
		return (execute_redirect_append(operator));
	else if (operator->ast_type == DLESS)
		return (execute_here_doc(operator));
	else if (operator->ast_type == PIPE)
		return (execute_pipe(operator));
	else
		return (EMPTY);
}

void	execute_ast(t_ast *node, t_ast **ast_list, t_token **token_list)
{
	if (node == NULL)
		return ;
	execute_ast(node->left, ast_list, token_list);
	if (node->ast_type >= 4 && node->ast_type <= 8)
	{
		printf("\n----------------------- ínicio do commando ------------------\n\n");
		if (execute_operator(node) == KO)
		{
			free_data(ast_list, token_list);
			exit(EXIT_FAILURE);
		}
		printf("\n----------------------- Fim do commando ------------------\n\n");
	}
	execute_ast(node->right, ast_list, token_list);
}

void	execute_single_cmd(t_ast *node, t_ast **ast_list, t_token **token_list)
{
	pid_t	pid;
	int		status;

	if (ft_strncmp(node->content, "exit", 5) == 0)
	{
		printf("exit\n");
		free_data(ast_list, token_list);
		exit(EXIT_SUCCESS);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execute_command(node->content) == FALSE)
		{
			free_data(ast_list, token_list);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}

void	begin_executing(t_ast **ast_list, t_token **token_list)
{
	t_ast	*root;

	if (ast_list == NULL || *ast_list == NULL)
		return ;
	root = *ast_list;
	if (root->right == NULL && root->left == NULL)
		execute_single_cmd(root, ast_list, token_list);
	else
		execute_ast(root, ast_list, token_list);
}
