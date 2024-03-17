/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:23:50 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/15 14:40:59 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	min_bot_b(t_stack **stack, int n)
{
	if ((*stack)->b->next->num == n)
		swap(stack, "sb");
}

static void	min_mid_b(t_stack **stack, int n)
{
	if ((*stack)->size_b == 3)
	{
		reverse_rotate(stack, "rrb");
		if ((*stack)->b->next->num == n)
			swap(stack, "sb");
	}
	else
	{
		rotate(stack, "rb");
		swap(stack, "sb");
		reverse_rotate(stack, "rrb");
		if ((*stack)->b->next->num == n)
			swap(stack, "sb");
	}
}

static void	min_top_b(t_stack **stack, int n)
{
	if ((*stack)->size_b == 3)
	{
		rotate(stack, "rb");
		if ((*stack)->b->next->num == n)
			swap(stack, "sb");
	}
	else
	{
		swap(stack, "sb");
		rotate(stack, "rb");
		swap(stack, "sb");
		reverse_rotate(stack, "rrb");
		if ((*stack)->b->next->num == n)
			swap(stack, "sb");
	}
}

void	sort_three_b(t_stack **stack)
{
	int	min_b;
	int	max_b;

	min_b = min_node(&(*stack)->b, 3);
	max_b = max_node(&(*stack)->b, 3);
	if ((*stack)->b->num == min_b)
		min_top_b(stack, max_b);
	else if ((*stack)->b->next->num == min_b)
		min_mid_b(stack, max_b);
	else if ((*stack)->b->next->next->num == min_b)
		min_bot_b(stack, max_b);
	stack_iter(stack, "pa", push, 3);
}

void	sort_stack_b(t_stack **stack, int size)
{
	int	mid;
	int	pushs;
	int	rotates;

	pushs = (size / 2) + (size % 2);
	rotates = 0;
	mid = mid_node((*stack)->b, pushs, size);
	while (pushs)
	{
		if ((*stack)->b->num >= mid && pushs--)
			push(stack, "pa");
		else
		{
			rotate(stack, "rb");
			rotates++;
		}
	}
	if ((*stack)->size_b > rotates)
		stack_iter(stack, "rrb", reverse_rotate, rotates);
}
