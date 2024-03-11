/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:43:04 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/11 02:41:08 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int	size_stack(t_node **stack)
{
	int		index;
	t_node	*temp;
	
	index = 0;
	if (!*stack)
		return (index);
	temp = *stack;
	while (temp)
	{
		index++;
		temp = temp->next;
	}
	return (index);
}

t_node	*list_last(t_node **stack)
{
	t_node	*temp;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return (*stack);
	temp = *stack;
	last = NULL;
	while (temp)
	{
		last = temp;
		temp = temp->next;
	}
	return (last);
}

void	retain_last_three(t_data *data)
{
	int	pushed;
	int	index;
	int	size_list;

	pushed = 0;
	index = 0;
	size_list = size_stack(&data->a);
	while (size_list > 6 && index < size_list && pushed < (size_list / 2))
	{
		data->size_a = size_stack(&data->a);
		if (data->size_a <= (size_list / 2))
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
