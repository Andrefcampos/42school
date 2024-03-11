/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/11 08:21:45 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	push_swap(int ac, char **av, t_data *data)
{
	if (ac < 5)
	{
		create_list(av, &data->a);
		data->max_a = max_node(&data->a);
		sort_three_num(data);
		return ;
	}
	//sort_all_num(data);
}

void	sort_three_num(t_data *data)
{
	if (data->a->next->next)
	{
		if (data->a->num == data->max_a)
			rotate(&data->a, "ra");
		else if (data->a->next->num == data->max_a)
			reverse_rotate(&data->a, "rra");
	}
	if (data->a->num > data->a->next->num)
		swap(&data->a, "sa");
}

/*void	sort_all_num(t_data *data)
{
	retain_last_three(data);
	sort_three_num(data);
	while (data->b)
	{

	}
	if (!check_sort(data->a))
		shift_stack(&data->a);
}*/
