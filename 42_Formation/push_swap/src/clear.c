/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:07:13 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/10 05:31:03 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

void	free_data(t_data **data)
{
	if ((*data)->a)
		list_clear(&(*data)->a);
	if ((*data)->b)
		list_clear(&(*data)->b);
	free(*data);
}

void	list_clear(t_node **head)
{
	t_node	*current;
	t_node	*next;

	if (*head)
	{
		current = *head;
		while (current)
		{
			next = current->next;
			if (current->prev != NULL)
				current->prev = NULL;
			free(current);
			current = NULL;
			current = next;
		}
	}
	*head = NULL;
}
