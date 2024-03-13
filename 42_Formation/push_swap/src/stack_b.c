/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:18:13 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 18:14:42 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_b(t_stack **stack, int *count, int size)
{
	t_var	vars;
	
	(*count)++;
	if (size > 8)
	{
		sort_all(stack, 'B', size);
		return ;
	}
	init_vars(&(*stack)->b, &vars, size);
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

	if (vars->ra > vars->rb)
	{
		rrr = vars->rb;
		list_iter(&(*stack)->a, "ra", reverse_rotate, (vars->ra - rrr));
	}
	else
	{
		rrr = vars->ra;
		list_iter(&(*stack)->b, "rb", reverse_rotate, (vars->rb - rrr));
	}
	stacks_iter(&(*stack)->a, &(*stack)->b, reverse_rotate_double, rrr);
}

void	divide_stack_b(t_stack **stack, t_var *vars, int *times)
{
	if (*times && (*stack)->b->num >= vars->small_pivot \
		&& (*stack)->b->next->num <= vars->small_pivot \
		&& (*stack)->b->num <= vars->big_pivot)
	{
		push(&(*stack)->b, &(*stack)->a, "pa");
		vars->pa++;
		rotate_double(&(*stack)->a, &(*stack)->b);
		vars->ra++;
		vars->rb++;
		(*times)--;
		return ;
	}
	if ((*stack)->b->num <= vars->small_pivot)
	{
		rotate(&(*stack)->b, "rb");
		vars->rb++;
		return ;
	}
	push(&(*stack)->b, &(*stack)->a, "pa");
	vars->pa++;
	if ((*stack)->a->num <= vars->big_pivot)
	{
		rotate(&(*stack)->a, "ra");
		vars->ra++;
	}
}
