/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.otg.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:58:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/26 23:06:48 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_node	*new_node(long nbr)
{
	t_node	*node;

	if (!nbr)
		return ;
	node = ft_calloc(sizeof(t_node), 1);
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

	if (!node)
		return (NULL);
	last = node;
	while (last->next != node)
		last = last->next;
	return (last);
}

t_node	*create_list(t_node *stack, int range, char **param)
{
	t_node	*node;
	t_node	*temp;
	int		i;
	
	node = new_node(ft_atol(param[1]));
	temp = node;
	i = 1;
	while (++i < range)
	{
		temp->next = new_node(ft_atol(param[i]));
		temp = temp->next;
	}
	temp->next = node;
	return (node);
}