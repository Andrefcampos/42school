/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:15:46 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 09:48:17 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	min_bot_a(t_node **head, char *move, int n)
{
	if ((*head)->next->num == n)
		swap(head, move);
	rotate(head, "ra");
	swap(head, move);
	reverse_rotate(head, "rra");
	swap(head, move);
}

void	min_mid_a(t_node **head, int n)
{
   swap(head, "sa");
   if ((*head)->next->num == n)
   {
      rotate(head, "ra");
      swap(head, "sa");
      reverse_rotate(head, "rra");
   }
}

void	min_top_a(t_node **head, int n)
{
	if ((*head)->next->num == n)
	{
		rotate(head, "ra");
		swap(head, "sa");
		reverse_rotate(head, "rra");
	}
}

void	sort_three_a(t_node **head_a, t_node **head_b)
{
	int	min_a;
	int	max_a;

	min_a = min_node(head_b, 3);
	max_a = max_node(head_b, 3);
	if (size_list(head_a) == 3)
		sort_three(head_a);
	if ((*head_b)->num == min_a)
		min_top_a(head_a, max_a);
	else if ((*head_b)->next->num == min_a)
		min_mid_a(head_a, max_a);
	else if ((*head_a)->next->next->num == min_a)
		min_bot_a(head_b, "sa", max_a);
}
