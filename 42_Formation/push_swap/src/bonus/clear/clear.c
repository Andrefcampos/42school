/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:07:13 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/18 19:59:31 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

void	free_stack(t_stack **stack)
{
	if ((*stack)->a)
		list_clear(&(*stack)->a);
	if ((*stack)->b)
		list_clear(&(*stack)->b);
	free(*stack);
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
