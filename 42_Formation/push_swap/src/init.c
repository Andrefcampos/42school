/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:23:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 18:15:44 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	init_stack(t_stack **stack, char **av)
{
	*stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return ;
	create_list(av, &(*stack)->a);
	(*stack)->size_a = size_list(&(*stack)->a);
	(*stack)->b = NULL;
	(*stack)->size_b = size_list(&(*stack)->b);
}

void	init_vars(t_node **stack, t_var *vars, int size)
{
	vars->big_pivot = mid_node(*stack, size / 2, size);
	vars->small_pivot = mid_node(*stack, size / 4 * 3, size);
	vars->ra = 0;
	vars->pa = 0;
	vars->rb = 0;
	vars->pb = 0;

}
