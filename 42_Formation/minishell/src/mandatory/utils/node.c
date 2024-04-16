/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:10:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/16 20:53:22 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../libs/libft/libft.h"
#include <stdlib.h>

t_node	*create_node(char *str)
{
	t_node	*aux;
	size_t	len;

	if (!str)
		return (NULL);
	aux = malloc(sizeof(t_node *) * 1);
	if (!aux)
		return (NULL);
	len = ft_strlen(str);
	aux->content = ft_calloc(sizeof(char), len + 1);
	if (!aux->content)
	{
		free(aux);
		return (NULL);
	}
	ft_memcpy(aux->content, str, len);
	aux->prev = NULL;
	aux->next = NULL;
	return (aux);
}

t_node	*last_node(t_node	**head)
{
	t_node	*temp;

	if (!*head)
		return (NULL);
	else if (*head && !(*head)->next)
		return (*head);
	temp = *head;
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}

void	add_last_node(t_node **head, t_node *node)
{
	t_node *temp;

	if ((!*head && !node) || !node)
		return ;
	else if (!*head && node)
	{
		*head = node;
		return ;
	}
	temp = last_node(head);
	node->prev = temp;
	temp->next = node;
	*head = temp;
}
