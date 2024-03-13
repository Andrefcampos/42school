/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:43:04 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 02:28:19 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int	size_stack(t_node **stack)
{
	int		index;
	t_node	*temp;
	
	index = 0;
	if (!*stack)
		return (index);
	temp = *stack;
	while (temp)
	{
		index++;
		temp = temp->next;
	}
	return (index);
}

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

int	mid_node(t_node **stack)
{
	t_node	*temp;
	t_node	*head;
	int		index;
	int		mid_n;

	if (!*stack || !(*stack)->next)
		return (0);
	head = *stack;
	temp = NULL;
	index = 0;
	mid_n = 0;
	list_copy(&head, &temp);
	while (index <= ((size_stack(&head) / 2) + (size_stack(&head) % 2)))
	{
		del_one_node(&temp, max_node(&temp));
		del_one_node(&temp, min_node(&temp));
		index++;
	}
	mid_n = max_node(&temp);
	list_clear(&temp);
	return (mid_n);
}
