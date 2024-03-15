/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:15:46 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/15 11:11:42 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	min_bot_a(t_stack **stack, int n)
{
	if ((*stack)->a->next->num == n)
		swap(stack, "sa");
	rotate(stack, "ra");
	swap(stack, "sa");
	reverse_rotate(stack, "rra");
	swap(stack, "sa");
}

static void	min_mid_a(t_stack **stack, int n)
{
   swap(stack, "sa");
   if ((*stack)->a->next->num == n)
   {
      rotate(stack, "ra");
      swap(stack, "sa");
      reverse_rotate(stack, "rra");
   }
}

static void	min_top_a(t_stack **stack, int n)
{
	if ((*stack)->a->next->num == n)
	{
		rotate(stack, "ra");
		swap(stack, "sa");
		reverse_rotate(stack, "rra");
	}
}

void	sort_three_a(t_stack **stack)
{
	int	min_a;
	int	max_a;

	min_a = min_node(&(*stack)->a, 3);
	max_a = max_node(&(*stack)->a, 3);
	if ((*stack)->size_a == 3)
		sort_three(stack);
	if ((*stack)->a->num == min_a)
		min_top_a(stack, max_a);
	else if ((*stack)->a->next->num == min_a)
		min_mid_a(stack, max_a);
	else if ((*stack)->a->next->next->num == min_a)
		min_bot_a(stack, max_a);
}

void	sort_stack_a(t_stack **stack, int size)
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
			push(stack, "pb");
		else
		{
			rotate(stack, "ra");
			rotates++;
		}
	}
	if ((*stack)->size_a > rotates)
		stack_iter(stack, "rra", reverse_rotate, rotates);
}
