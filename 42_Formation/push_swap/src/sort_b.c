/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:23:50 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/14 15:54:10 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	min_bot_b(t_node **head, char *move, int n)
{
	if ((*head)->next->num == n)
		swap(head, move);
}

void	min_mid_b(t_node **head, int size, int n)
{
	if (size == 3)
	{
		reverse_rotate(head, "rrb");
		if ((*head)->next->num == n)
			swap(head, "sb");
	}
	else
	{
		rotate(head, "rb");
		swap(head, "sb");
		reverse_rotate(head, "rrb");
		if ((*head)->next->num == n)
			swap(head, "sb");
	}
}

void	min_top_b(t_node **head, int size, int n)
{
	if (size == 3)
	{
		rotate(head, "rb");
		if ((*head)->next->num == n)
			swap(head, "sb");
	}
	else
	{
		swap(head, "sb");
		rotate(head, "rb");
		swap(head, "sb");
		reverse_rotate(head, "rrb");
		if ((*head)->next->num == n)
			swap(head, "sb");
	}
}

void	sort_three_b(t_stack **stack)
{
	int	min_b;
	int	max_b;

	min_b = min_node(&(*stack)->b, 3);
	max_b = max_node(&(*stack)->b, 3);
	if ((*stack)->b->num == min_b)
		min_top_b(&(*stack)->b, (*stack)->size_b, max_b);
	else if ((*stack)->b->next->num == min_b)
		min_mid_b(&(*stack)->b, (*stack)->size_b, max_b);
	else if ((*stack)->b->next->next->num == min_b)
		min_bot_b(&(*stack)->b, "sb", max_b);
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
			rotate(&(*stack)->b, "rb");
			rotates++;
		}
	}
	if ((*stack)->size_b > rotates)
		list_iter(&(*stack)->b, "rrb", reverse_rotate, rotates);
}
