/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:51:11 by mavitori          #+#    #+#             */
/*   Updated: 2024/05/02 00:59:20 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

t_ast	*ast_lstnew(char *content, tokens token_type)
{
	t_ast	*node;

	node = (t_ast *)malloc(sizeof(t_ast));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->ast_type = type_check(content, token_type); // função de promoção de tipos para ast;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	ast_lstclear(t_ast **lst)
{
	t_ast	*current;
	t_ast	*right;

	if (*lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		right = current->right;
		if (current->left != NULL)
			ast_lstclear(&(current->left));
		free(current->content);
		free(current);
		current = right;
	}
	*lst = NULL;
}

void	ast_lstadd_left(t_ast **lst, t_ast *new)
{
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	t_ast *last = *lst;
	while (last->left != NULL)
		last = last->left;
	last->left = new;
}

void	ast_lstadd_right(t_ast **lst, t_ast *new)
{
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	t_ast *last = *lst;
	while (last->right != NULL)
		last = last->right;
	last->right = new;
}
