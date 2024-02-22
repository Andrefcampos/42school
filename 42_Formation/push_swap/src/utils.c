/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:58:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/22 18:37:22 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	creat_node(t_node *node, int content)
{
	if (!content)
		return ;
	node = malloc(sizeof(t_node));
	node->val = content;
	node->next = NULL;
}

void	add_node_in_back(t_node **node, int content)
{
	if (!content)
		return ;
	while (*node)
		*node = (*node)->next;
	(*node)->val = content;
}
