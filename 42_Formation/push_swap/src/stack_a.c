/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:50:55 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/15 17:12:21 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_a(t_stack **stack, int *count, int size)
{
	t_var	vars;

	if (size < 8)
	{
		sort_stacks(stack, 'A', size);
		return ;
	}
	init_vars((*stack)->a, &vars, size);
	while (size--)
		divide_stack_a(stack, &vars, &size);

	restore_a(stack, &vars, count);
	sort_a(stack, count, vars.ra);
	sort_b(stack, count, vars.rb);
	sort_b(stack, count, vars.pb - vars.rb);
}

void	divide_stack_a(t_stack **stack, t_var *vars, int *times)
{
	if (*times && (*stack)->a->num < vars->big_pivot \
		&& (*stack)->a->next->num > vars->big_pivot \
		&& (*stack)->a->num > vars->small_pivot)
	{
		push(stack, "pb");
		vars->pb++;
		rotate(stack, "rr");
		vars->ra++;
		vars->rb++;
		(*times)--;
		return ;
	}
	if ((*stack)->a->num > vars->big_pivot)
	{
		rotate(stack, "ra");
		vars->ra++;
		return ;
	}
	push(stack, "pb");
	vars->pb++;
	if ((*stack)->b->num > vars->small_pivot)
	{
		rotate(stack, "rb");
		vars->rb++;
	}
}

void	restore_a(t_stack **stack, t_var *vars, int *count)
{
	int	rrr;
	int	rrx;

	if (vars->ra > vars->rb)
	{
		rrr = vars->rb;
		rrx = vars->ra - rrr;
		if ((*count) > 0)
			stack_iter(stack, "rra", reverse_rotate, rrx);
		else
			stack_iter(stack, "rrb", reverse_rotate, rrr);
	}
	else
	{
		rrr = vars->ra;
		rrx = vars->rb - rrr;
		if ((*count) > 0)
			stack_iter(stack, "rrb", reverse_rotate, rrx);
		else
			stack_iter(stack, "rrb", reverse_rotate, vars->rb);
	}
	if ((*count) > 0)
			stack_iter(stack, "rrr", reverse_rotate, rrr);
}
