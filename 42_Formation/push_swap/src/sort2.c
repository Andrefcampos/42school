/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:52:14 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/14 16:26:21 by andrefil         ###   ########.fr       */
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
			swap(&(*stack)->b, "sb");
		stack_iter(stack, "pa", push, 2);
	}
	else if (size == 2)
	{
		if ((*stack)->a->num > (*stack)->a->next->num)
			swap(&(*stack)->a, "sa");
	}
	else if (size == 1 && c == 'B')
		push(stack, "pa");
	return (1);
}
