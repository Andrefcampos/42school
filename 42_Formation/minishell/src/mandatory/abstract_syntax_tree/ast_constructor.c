/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:51:11 by mavitori          #+#    #+#             */
/*   Updated: 2024/05/02 00:59:09 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	build_ast_node(t_token *new_node, t_ast **ast_list, int state)
{
	t_ast	*new;

	new = ast_lstnew(ft_strdup(new_node->content), new_node->token);
	if (state == LEFT)
		ast_lstadd_left(ast_list, new);
	else
		ast_lstadd_right(ast_list, new);
	return ;
}

t_ast	*break_in_two(t_token *current, t_ast **ast_list, int state)
{
	t_ast	*current_ast_node;

	current_ast_node = ast_lstnew(ft_strdup(current->content), current->token);

	if (state == FALSE)
		ast_lstadd_right(ast_list, current_ast_node);
	else
		ast_lstadd_left(ast_list, current_ast_node);

	// Limpar o nó atual da lista do tipo t_token
	free (current->content);
	current->content = NULL;
	current->token = NONE;

	// pegar todos os tokens antes do current
	if (current->prev != NULL)
	{
		if (current->prev->prev == NULL || current->prev->prev->token == NONE)
			build_ast_node(current->prev, &current_ast_node, LEFT);
		else
			current_ast_node->left_token = current->prev;
	}
	// pegar todos os tokens antes do current = right
	if (current->next != NULL)
	{
		if (current->next->next == NULL || current->next->next->token == NONE)
			build_ast_node(current->next, &current_ast_node, RIGHT);
		else
			current_ast_node->right_token = current->next;
	}
	return (current_ast_node);
}

void	continue_division_left(tokens operator, t_ast *ast_current_node, t_ast **ast_list)
{
	t_ast	*node_ast;
	t_token	*current;

	// lado esquerdo
	if (ast_current_node->left != NULL || ast_current_node->left_token == NULL)
		return;

	current = ast_current_node->left_token;
	while (current != NULL)
	{
		if (current->token == operator)
		{
			node_ast = break_in_two(current, ast_list, TRUE);
			continue_division_left(operator, node_ast, ast_list);
			continue_division_right(operator, node_ast, ast_list);
		}
		else
			current = current->prev;
	}
}

void	continue_division_right(tokens operator, t_ast *ast_current_node, t_ast **ast_list)
{
	t_ast	*node_ast;
	t_token	*current;

	// lado esquerdo
	if (ast_current_node->right != NULL || ast_current_node->right_token == NULL)
		return;

	current = ast_current_node->right_token;
	while (current != NULL)
	{
		if (current->token == operator)
		{
			node_ast = break_in_two(current, ast_list, FALSE);
			continue_division_left(operator, node_ast, ast_list);
			continue_division_right(operator, node_ast, ast_list);
		}
		else
			current = current->next;
	}
}

int	start_ast(t_token **token_list, tokens operator, t_ast **ast_list)
{
	t_token	*current;
	t_ast	*first_node;

	current = token_lstlast(*token_list);
	while (current->prev != NULL)
	{
		if (current->token == operator)
		{
			first_node = break_in_two(current, ast_list, 0); // verificar a utilização dessa variavel, pois ao que parece ela não está sendo usada.
			return (TRUE) ;
		}
		else
			current = current->prev;
	}
	return (FALSE);
}

void	scan_token_list(t_token **token_list, t_ast **ast_list)
{
	t_token		*current;
	int			operator;
	int			start;

	current = token_lstlast(*token_list);
	operator = PIPE;
	start = FALSE;
	if (current->prev == NULL)
	{
		build_ast_node(current, ast_list, LEFT);
		return ;
	}
	while (operator > 3)
	{
		start = start_ast(token_list, operator, ast_list);
		if (start == FALSE)
			operator--;
		else
			break ;
	}
	if (start == TRUE)
	{
		while (operator > 3)
		{
			// recursao para quebrar o lado esquedo e direito
			continue_division_left(operator, *ast_list, ast_list);
			continue_division_right(operator, *ast_list, ast_list);
			operator--;
		}
	}
}
