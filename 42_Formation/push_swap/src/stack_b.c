/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:18:13 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/15 17:20:12 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_b(t_stack **stack, int *count, int size)
{
	t_var	vars;
	
	(*count)++;
	if (size < 8)
	{
		sort_stacks(stack, 'B', size);
		return ;
	}
	init_vars((*stack)->b, &vars, size);
	while (size--)
		divide_stack_b(stack, &vars, &size);
	sort_a(stack, count, vars.pa - vars.ra);
	restore_b(stack, &vars);
	sort_a(stack, count, vars.ra);
	sort_b(stack, count, vars.rb);
}

void	restore_b(t_stack **stack, t_var *vars)
{
	int	rrr;
	int	rrx;

	if (vars->ra > vars->rb)
	{
		rrr = vars->rb;
		rrx = vars->ra - rrr;
		stack_iter(stack, "rra", reverse_rotate, rrx);
	}
	else
	{
		rrr = vars->ra;
		rrx = vars->rb - rrr;
		stack_iter(stack, "rrb", reverse_rotate, rrx);
	}
	stack_iter(stack, "rrr", reverse_rotate, rrr);
}

void	divide_stack_b(t_stack **stack, t_var *vars, int *times)
{
	if (*times && (*stack)->b->num >= vars->small_pivot \
		&& (*stack)->b->next->num <= vars->small_pivot \
		&& (*stack)->b->num <= vars->big_pivot)
	{
		push(stack, "pa");
		vars->pa++;
		rotate(stack, "rr");
		vars->ra++;
		vars->rb++;
		(*times)--;
		return ;
	}
	if ((*stack)->b->num <= vars->small_pivot)
	{
		rotate(stack, "rb");
		vars->rb++;
		return ;
	}
	push(stack, "pa");
	vars->pa++;
	if ((*stack)->a->num <= vars->big_pivot)
	{
		rotate(stack, "ra");
		vars->ra++;
	}
}
