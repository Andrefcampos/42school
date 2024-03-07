/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/07 19:13:00 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	order_three_num(t_node **head)
{
	if ((*head)->num > (*head)->next->num)
		swap_first_second_node(head);
	if ((*head)->num > (*head)->next->next->num)
		swap_last_first_node(head);
	if ((*head)->next->num > (*head)->next->next->num)
		swap_second_last_node(head);
	if (!check_orders(head))
		order_three_num(head);
	else
		return ;
}

int	check_orders(t_node **head)
{
	t_node	*temp;
	t_node	*current_node;

	current_node = *head;
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
