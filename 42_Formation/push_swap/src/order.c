/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/08 03:15:14 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	push_swap(int ac, char **av, t_data *data)
{
	if (ac < 5)
	{
		create_list(av, &data->a);
		order_three_num(data);
		return ;
	}

}

int	order_three_num(t_data *data)
{
	if (!data->a || !data->a->next)
		return (0) ;
	if (data->a->num > data->a->next->num)
		swap_first_second_node(&data->a);
	if (data->a->num > data->a->next->next->num)
		swap_last_first_node(&data->a);
	if (data->a->next->num > data->a->next->next->num)
		rotate_all_stack(&data->a);
	if (!check_orders(&data->a))
		order_three_num(data);
	return (1) ;
}

int	check_orders(t_node **head)
{
	t_node	*temp;
	t_node	*current_node;
	
	if (!*head || !(*head)->next)
		return (1);
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
