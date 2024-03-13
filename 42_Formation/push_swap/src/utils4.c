/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:43:04 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 06:03:59 by andrefil         ###   ########.fr       */
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
	int		mid_n;
	int		big_n;
	int		small_n;

	if (!head || !(head)->next)
		return (0);
	big_n = max_node(&head, size);
	small_n = min_node(&head, size);
	while (--range)
	{
		mid_n = small_n;
		temp = head;
		index = 0;
		while (temp && index++ < size)
		{
			if (temp->num > mid_n && temp->num < big_n)
				mid_n = temp->num;
			temp = temp->next;
		}
		big_n = mid_n;
	}
	return (mid_n);
}
