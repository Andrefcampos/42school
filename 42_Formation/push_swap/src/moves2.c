/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:29:52 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/11 08:17:32 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	swap_double(t_node **stack_1, t_node **stack_2)
{
	swap_first_second_node(stack_1);
	swap_first_second_node(stack_2);
	ft_putendl_fd("ss", 1);
}

void	rotate_double(t_node **stack_1, t_node **stack_2)
{
	send_first_to_last(stack_1);
	send_first_to_last(stack_2);
	ft_putendl_fd("rr", 1);
}

void	reverse_rotate_double(t_node **stack_1, t_node **stack_2)
{
	send_last_to_first(stack_1);
	send_last_to_first(stack_2);
	ft_putendl_fd("rrr", 1);
}

