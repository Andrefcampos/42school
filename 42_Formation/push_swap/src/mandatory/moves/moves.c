/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:49:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/17 14:29:43 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	swap(t_stack **stack, char *move)
{
	if (move[0] == 's')
	{
		if ((move[1] == 'a' && (*stack)->size_a < 2) \
			|| (move[1] == 'b' && (*stack)->size_b < 2))
			return ;
		if (move[1] == 'a' && (*stack)->size_b > 1 \
			&& (*stack)->b->num < (*stack)->b->next->num)
			move = "ss";
		else if (move[1] == 'b' && (*stack)->size_a > 1 \
				&& (*stack)->a->num > (*stack)->a->next->num)
			move = "ss";
		if (move[1] == 'a' || move [1] == 's')
			swap_first_second_node(&(*stack)->a);
		if (move[1] == 'b' || move[1] == 's')
			swap_first_second_node(&(*stack)->b);
		ft_putendl_fd(move, 1);
	}
}

void	push(t_stack **stack, char *move)
{
	if (move[0] == 'p')
	{
		if (move[1] == 'b' && (*stack)->a)
		{
			send_in_list(&(*stack)->a, &(*stack)->b);
			(*stack)->size_a--;
			(*stack)->size_b++;
		}
		else if (move[1] == 'a' && (*stack)->b)
		{
			send_in_list(&(*stack)->b, &(*stack)->a);
			(*stack)->size_a++;
			(*stack)->size_b--;
		}
		else
			return ;
		ft_putendl_fd(move, 1);
	}
}

void	rotate(t_stack **stack, char *move)
{
	if (move[0] == 'r')
	{
		if ((move[1] == 'a' && (*stack)->size_a == 0) \
			|| (move[1] == 'b' && (*stack)->size_b == 0))
			return ;
		if (move[1] == 'a' || move[1] == 'r')
			send_first_to_last(&(*stack)->a);
		if (move[1] == 'b' || move[1] == 'r')
			send_first_to_last(&(*stack)->b);
		ft_putendl_fd(move, 1);
	}
}

void	reverse_rotate(t_stack **stack, char *move)
{
	if (move[0] == 'r' && move[1] == 'r')
	{
		if ((move[2] == 'a' && (*stack)->size_a == 0) \
			|| (move[2] == 'b' && (*stack)->size_b == 0))
			return ;
		if (move[2] == 'a' || move[2] == 'r')
			send_last_to_first(&(*stack)->a);
		if (move[2] == 'b' || move[2] == 'r')
			send_last_to_first(&(*stack)->b);
		ft_putendl_fd(move, 1);
	}
}
