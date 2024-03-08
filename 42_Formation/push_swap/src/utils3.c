/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:52:32 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/08 17:16:20 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	max_node(t_node **head)
{
	t_node	*temp;
	int		max;

	temp = *head;
	max = temp->num;
	while (temp)
	{
		if (max <= temp->num)
			max = temp->num;
		temp = temp->next;
	}
	return (max);
}

int	min_node(t_node **head)
{
	t_node	*temp;
	int	min;

	temp = *head;
	min = temp->num;
	while (temp)
	{
		if (min >= temp->num)
		min = temp->num;
	temp = temp->next;
	}
	return (min);
}
