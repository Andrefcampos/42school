/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:50:55 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 18:16:13 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_a(t_stack **stack, int *count, int size)
{
	t_var	vars;

	if (size < 8)
	{
		sort_all(stack, 'A', size);
		return ;
	}
	init_vars(&(*stack)->a, &vars, size);
	while (size)
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
		push(&(*stack)->a, &(*stack)->b, "pb");
		vars->pb++;
		rotate_double(&(*stack)->a, &(*stack)->b);
		vars->ra++;
		vars->rb++;
		(*times)--;
		return ;
	}
	if ((*stack)->a->num > vars->big_pivot)
	{
		rotate(&(*stack)->a, "ra");
		vars->ra++;
		return ;
	}
	push(&(*stack)->a, &(*stack)->b, "pb");
	vars->pb++;
	if ((*stack)->b->num > vars->small_pivot)
	{
		rotate(&(*stack)->b, "rb");
		vars->rb++;
	}
}

void	restore_a(t_stack **stack, t_var *vars, int *count)
{
	int	rrr;

	if (vars->ra > vars->rb)
	{
		rrr = vars->rb;
		if (*count > 0)
			list_iter(&(*stack)->a, "rra", reverse_rotate, (vars->ra - rrr));
		else
			list_iter(&(*stack)->a, "ra", rotate, rrr);
	}
	else
	{
		rrr = vars->ra;
		if (*count > 0)
			list_iter(&(*stack)->b, "rrb", reverse_rotate, (vars->rb - rrr));
		else
			list_iter(&(*stack)->b, "rrb", reverse_rotate, vars->rb);
	}
	if (*count > 0)
		stacks_iter(&(*stack)->a, &(*stack)->b, reverse_rotate_double, rrr);
}
