/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:43:04 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/11 10:18:04 by andrefil         ###   ########.fr       */
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

void	create_list(char **av, t_node **stack)
{
	int	y;

	y = 1;
	while (av[y])
	{
		list_add_next_last(stack, create_node(ft_atol(av[y])));
		y++;
	}
}

/*void	get_index(t_node **stack)
{
	t_node	*temp;
	int		index;

	temp = *stack;
	index = 2;
	while (index <= max_node(stack))
	{
		if (temp->num == max_node(stack))
			temp->index = size_stack(stack);
		if (temp->num == min_node(stack))
			temp->index = 1;
		if (temp->index != 0)
			temp = temp->next;
		index++;
	}
}*/
