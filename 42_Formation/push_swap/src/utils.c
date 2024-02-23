/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:58:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/23 17:17:03 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	create_node(t_node **node, int content)
{
	if (!content)
		return ;

}

void	add_node_in_back(t_node **node, int content)
{
	t_node	*last;
	t_node	*new;

	if (!content)
		return ;
	if (!(*node))
	{
		creat_node(node, content);
		return ;
	}
	last = *node;
	while (last != *node)
		last = last->next;
	creat_node(new, content);
	new->prev = last;
	node = new;
	free(new);
}
