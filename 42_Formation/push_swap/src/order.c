/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/06 20:50:46 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	order_three_num(t_node **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		swap_first_second_node(stack_a);
	if ((*stack_a)->num > (*stack_a)->next->next->num)
		swap_last_first_node(stack_a);
	if ((*stack_a)->next->num > (*stack_a)->next->next->num)
		swap_second_last_node(stack_a);
}
