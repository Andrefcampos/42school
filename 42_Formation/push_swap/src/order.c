/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/08 17:21:52 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <push_swap.h>

void	push_swap(int ac, char **av, t_data *data)
{
	if (ac < 5)
	{
		create_list(av, &data->a);
		order_three_num(data);
		return ;
	}
}

void	order_three_num(t_data *data)
{
	if (!data->a || !data->a->next)
		return ;
	if (data->a->num > data->a->next->num)
	{
		swap_first_second_node(&data->a);
		ft_putendl_fd("sa", 1);
	}
	if (data->a->next->next)
	{
		if (data->a->num > data->a->next->next->num)
		{
			swap_last_first_node(&data->a);
			ft_putendl_fd("ra", 1);
		}
		if (data->a->next->num > data->a->next->next->num)
		{
			rotate_all_stack(&data->a);
			ft_putendl_fd("rra", 1);
		}
	}
	if (!check_orders(&data->a))
		order_three_num(data);
	else
		return ;
}

void	order_five_num(t_data *data)
{
	if (!data->a || !data->a->next)
		return ;
	if (data->a->num > data->a->next->num)
	{
		swap_first_second_node(&data->a);
	}	
}
