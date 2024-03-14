/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:49:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/14 12:37:54 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	swap(t_node **stack, char *move)
{
	swap_first_second_node(stack);
	ft_putendl_fd(move, 1);
}

void	push(t_stack **stack, char *move)
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

void	rotate(t_node **stack, char *move)
{
	send_first_to_last(stack);
	ft_putendl_fd(move, 1);
}

void	reverse_rotate(t_node **stack, char *move)
{
	send_last_to_first(stack);
	ft_putendl_fd(move, 1);
}
