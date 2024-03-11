/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:49:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/11 08:16:53 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	swap(t_node **stack, char *move)
{
	swap_first_second_node(stack);
	ft_putendl_fd(move, 1);
}

void	push(t_node **stack_1, t_node **stack_2, char *move)
{
	send_in_list(stack_1, stack_2);
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
