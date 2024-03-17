/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:43:04 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/17 14:11:37 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int	size_list(t_node **head)
{
	int		index;
	t_node	*temp;

	index = 0;
	if (!*head)
		return (index);
	temp = *head;
	while (temp)
	{
		index++;
		temp = temp->next;
	}
	return (index);
}

int	max_node(t_node **head, int size)
{
	t_node	*temp;
	int		max;

	if (!*head)
		return (0);
	temp = *head;
	max = temp->num;
	while (temp && size--)
	{
		if (max < temp->num)
			max = temp->num;
		if (temp->next)
			temp = temp->next;
	}
	return (max);
}

int	min_node(t_node **head, int size)
{
	t_node	*temp;
	int		min;

	if (!*head)
		return (0);
	temp = *head;
	min = temp->num;
	while (temp && size--)
	{
		if (min > temp->num)
			min = temp->num;
		if (temp->next)
			temp = temp->next;
	}
	return (min);
}

int	mid_node(t_node *head, int range, int size)
{
	t_node	*temp;
	int		index;
	int		min;
	int		big_n;
	int		small_n;

	big_n = max_node(&head, size);
	small_n = min_node(&head, size);
	while (--range)
	{
		min = small_n;
		temp = head;
		index = 0;
		while (temp && index++ < size)
		{
			if (temp->num > min && temp->num < big_n)
				min = temp->num;
			temp = temp->next;
		}
		big_n = min;
	}
	return (min);
}
