/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/06 21:52:04 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	order_three_num(t_node **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		swap_first_second_node(stack_a);
	if ((*stack_a)->num > (*stack_a)->next->next->num)
		swap_last_first_node(stack_a);
	if ((*stack_a)->next->num > (*stack_a)->next->next->num)
		swap_second_last_node(stack_a);
	if (!check_orders(stack_a))
		order_three_num(stack_a);
	else
		return ;
}

int	check_orders(t_node **stack_a)
{
	t_node	*temp;
	t_node	*current_node;

	current_node = *stack_a;
	while (current_node)
	{
		temp = current_node->next;
		while (temp)
		{
			if (current_node->num > temp->num)
				return (0);
			temp = temp->next;
		}
		current_node = current_node->next;
	}
	return (1);
}
