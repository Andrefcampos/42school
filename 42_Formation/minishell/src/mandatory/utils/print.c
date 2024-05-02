/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:26:13 by andrefil          #+#    #+#             */
/*   Updated: 2024/05/02 00:58:55 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	print_token_bash(t_token **list)
{
	t_token	*current;

	current = *list;
	printf("Token list:\n");
	printf("[");
	while (current != NULL)
	{
		if (current->next == NULL)
			printf("'%s'", current->content);
		else
			printf("'%s', ", current->content);
		current = current->next;
	}
	printf("]\n");
	return ;
}

void	print_token(t_token **list)
{
	t_token	*current;

	current = *list;
	printf("Token list:\n");
	printf("--------------------------------------------------------------\n");
	while (current != NULL)
	{
		if (current->prev != NULL)
		{
			printf("Previous content: %s\n", current->prev->content);
		}
		else
		{
			printf("No previous content\n");
		}
		printf("Content: %s, Type: %d\n", current->content, current->token);
		if (current->next != NULL)
		{
			printf("Next content: %s\n", current->next->content);
		}
		else
		{
			printf("No next content\n");
		}
		printf("--------------------------------------------------------------\n");
		current = current->next;
	}
	return ;
}

void	print_ast(t_ast **list)
{
	t_ast	*current;

	current = *list;
	printf("ast list:\n");
	printf("--------------------------------------------------------------\n");
	printf("\nPRINCIPAL: %s\n", current->content);
	printf("\n DIREITA: %s\n", current->right->content);
	printf("\n ESQUERDA: %s\n", current->left->content);
	printf("\n ESQUERDA - esquerda: %s\n", current->left->left->content);
	printf("\n ESQUERDA - direita: %s\n", current->left->right->content);
	printf("--------------------------------------------------------------\n");
	return ;
}
