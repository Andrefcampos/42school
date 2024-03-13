/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/12 15:37:56 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	push_swap(int ac, t_stack *stack)
{
	if (ac < 5)
		sort_three_num(stack);
	//else
		//sort_all_num(stack);
}

void	sort_three_num(t_stack *stack)
{
	if (stack->a->next->next)
	{
		if (stack->a->num == max_node(&stack->a))
			rotate(&stack->a, "ra");
		else if (stack->a->next->num == max_node(&stack->a))
			reverse_rotate(&stack->a, "rra");
	}
	if (stack->a->num > stack->a->next->num)
		swap(&stack->a, "sa");
}

void	retain_last_three(t_stack *stack)
{
	int	pushed;
	int	index;
	int	size_list;

	pushed = 0;
	index = 0;
	size_list = stack->size_a;
	while (size_list > 6 && index < size_list && pushed < (size_list / 2))
	{
		stack->size_a = size_stack(&stack->a);
		if (stack->a->num <= mid_node(&stack->a))
		{
			push(&stack->a, &stack->b, "pb");
			pushed++;
		}
		else
			rotate(&stack->a, "ra");
		index++;
	}
	while ((size_list - pushed) > 3)
	{
		push(&stack->a, &stack->b, "pb");
		pushed++;
	}
}

/*void	sort_all_num(t_stack *stack)
{
	retain_last_three(stack);
	sort_three_num(stack);
	while (stack->b)
	{

	}
	if (!check_sort(stack->a))
		shift_stack(&stack->a);
}*/

/*void	shift_stack(t_stack *stack)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = stack_size(stack->a);
	lowest_pos = 
	

}*/
