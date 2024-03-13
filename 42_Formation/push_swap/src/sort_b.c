/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:23:50 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 08:47:32 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	min_bot_b(t_node **head, char *move, int n)
{
	if ((*head)->next->num == n)
		swap(head, move);
}

void	min_mid_b(t_node **head, int size, int n)
{
	if (size == 3)
	{
		reverse_rotate(head, "rrb");
		if ((*head)->next->num == n)
			swap(head, "sb");
	}
	else
	{
		rotate(head, "rb");
		swap(head, "sb");
		reverse_rotate(head, "rrb");
		if ((*head)->next->num == n)
			swap(head, "sb");
	}
}

void	min_top_b(t_node **head, int size, int n)
{
	if (size == 3)
	{
		rotate(head, "rb");
		if ((*head)->next->num == n)
			swap(head, "sb");
	}
	else
	{
		swap(head, "sb");
		rotate(head, "rb");
		swap(head, "sb");
		reverse_rotate(head, "rrb");
		if ((*head)->next->num == n)
			swap(head, "sb");
	}
}

void	sort_three_b(t_node **head_b, t_node **head_a)
{
	int	min_b;
	int	max_b;

	min_b = min_node(head_b, 3);
	max_b = max_node(head_b, 3);
	if ((*head_b)->num == min_b)
		min_top_b(head_b, size_list(head_b), max_b);
	else if ((*head_b)->next->num == min_b)
		min_mid_b(head_b, size_list(head_b), max_b);
	else if ((*head_b)->next->next->num == min_b)
		min_bot_b(head_b, "sb", max_b);
	push(head_b, head_a, "pa");
	push(head_b, head_a, "pa");
	push(head_b, head_a, "pa");
}
