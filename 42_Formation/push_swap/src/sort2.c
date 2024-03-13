/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:52:14 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 10:38:50 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_handle_a(t_stack **stack, int size)
{
	int	mid;
	int	pushs;
	int	rotates;

	pushs = (size / 2);
	rotates = 0;
	mid = mid_node((*stack)->a, pushs + (size % 2), size);
	while (pushs)
	{
		if ((*stack)->a->num < mid && pushs--)
			push(&(*stack)->a, &(*stack)->b, "pb");
		else
		{
			rotate(&(*stack)->a, "ra");
			rotates++;
		}
	}
	if ((*stack)->size_a > rotates)
	{
		while (rotates--)
			reverse_rotate(&(*stack)->a, "rra");
	}
}

void	sort_handle_b(t_stack **stack, int size)
{
	int	mid;
	int	pushs;
	int	rotates;

	pushs = (size / 2) + (size % 2);
	rotates = 0;
	mid = mid_node((*stack)->b, pushs + (size % 2), size);
	while (pushs)
	{
		if ((*stack)->b->num < mid && pushs--)
			push(&(*stack)->b, &(*stack)->a, "pa");
		else
		{
			rotate(&(*stack)->b, "ra");
			rotates++;
		}
	}
	if ((*stack)->size_a > rotates)
	{
		while (rotates--)
			reverse_rotate(&(*stack)->b, "rrb");
	}
}

int	check_sort_stacks(t_stack **stack, char c, int size)
{
	if (size > 3)
		return (0);
	else if (size == 3 && c == 'A')
		sort_three_a(&(*stack)->a, &(*stack)->b);
	else if (size == 3)
		sort_three_b(&(*stack)->b, &(*stack)->a);
	else if (size == 2 && c == 'B')
	{
		if ((*stack)->b->num < (*stack)->b->next->num)
			swap(&(*stack)->b, "sb");
		push(&(*stack)->b, &(*stack)->a, "pb");
		push(&(*stack)->b, &(*stack)->a, "pb");
	}
	else if (size == 1 && c == 'B')
		push(&(*stack)->b, &(*stack)->a, "pb");
	return (1);
}
