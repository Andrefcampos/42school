/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/11 09:46:16 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	push_swap(int ac, t_data *data)
{
	if (ac < 5)
		sort_three_num(data);
	else
		//sort_all_num(data);
	return ;
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

void	retain_last_three(t_data *data)
{
	int	pushed;
	int	index;
	int	size_list;

	pushed = 0;
	index = 0;
	size_list = data->size_a;
	while (size_list > 6 && index < size_list && pushed < (size_list / 2))
	{
		data->size_a = size_stack(&data->a);
		if (data->size_a >= (size_list / 2)) //corrigir o comparador de a.
		{
			push(&data->a, &data->b, "pb");
			pushed++;
		}
		else
			rotate(&data->a, "ra");
		index++;
	}
	while ((size_list - pushed) > 3)
	{
		push(&data->a, &data->b, "pb");
		pushed++;
	}
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

/*void	shift_stack(t_data *data)
{
	

}*/
