/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:58:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/26 15:51:23 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_node	*new_node(long nbr)
{
	t_node	*node;

	if (!nbr)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = nbr;
	node->next = NULL;
	node->prev = node;
	return (node);
}

t_node	*node_last(t_node *node)
{
	t_node	*last;

	last = node;
	while (last->next != node)
		last = last->next;
	return (last);
}
