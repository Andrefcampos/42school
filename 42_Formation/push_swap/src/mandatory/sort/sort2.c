/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:52:14 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/19 11:52:50 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_sort_stacks(t_stack **stack, char c, int size)
{
	if (size > 3)
		return (0);
	else if (size == 3 && c == 'A')
		sort_three_a(stack);
	else if (size == 3)
		sort_three_b(stack);
	else if (size == 2 && c == 'B')
	{
		if ((*stack)->b->num < (*stack)->b->next->num)
			swap(stack, "sb");
		stack_iter(stack, "pa", push, size);
	}
	else if (size == 2)
	{
		if ((*stack)->a->num > (*stack)->a->next->num)
			swap(stack, "sa");
	}
	else if (size == 1 && c == 'B')
		push(stack, "pa");
	return (1);
}

int	check_sort(t_node **head)
{
	t_node	*temp;
	t_node	*current_node;

	if (!*head || !(*head)->next)
		return (1);
	current_node = *head;
	while (current_node)
	{
		temp = current_node->next;
		while (temp)
		{
			if (current_node->num > temp->num)
				return (0);
			temp = temp->next;
		}
		current_node = current_node->next;
	}
	return (1);
}

int	check_n_sort(t_node **head, char c, int size)
{
	t_node	*temp;

	temp = *head;
	while (temp && --size)
	{
		if (c == 'A' && temp->next && temp->num > temp->next->num)
			return (0);
		else if (temp->next && temp->num < temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
