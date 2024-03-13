/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 11:31:04 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	push_swap(int ac, t_stack *stack)
{
	if (ac < 5)
		sort_three(&stack->a);
	else if (ac < 6)
		sort_four();
	else if (ac < 7)
		sort_five();
	//else
		//sort(stack);
}

void	sort_three(t_node **head)
{
	if ((*head)->next->next)
	{
		if ((*head)->num == max_node(head, 3))
			rotate(head, "ra");
		else if ((*head)->next->num == max_node(head, 3))
			reverse_rotate(head, "rra");
	}
	if ((*head)->num > (*head)->next->num)
		swap(head, "sa");
}


void	sort_all(t_stack **stack, char c, int size)
{
	if (check_sort_stacks(stack, c, size))
		return ;
	if (c == 'A')
	{
		if (!check_n_sort(&(*stack)->a, c, size))
			sort_handle_a(stack, size);
		else
			return ;
	}
	else
	{
		if (!check_n_sort(&(*stack)->b, c, size))
			sort_handle_b(stack, size);
		else
		{
			push(&(*stack)->b, &(*stack)->a, "pb");
			return ;
		}
	}
	sort_all(stack, 'A', ((size / 2) + (size % 2)));
	sort_all(stack, 'B', (size / 2));
}


// void	retain_last_three(t_stack *stack)
// {
// 	int	pushed;
// 	int	index;
// 	int	list_size;
// 
// 	pushed = 0;
// 	index = 0;
// 	list_size = stack->size_a;
// 	while (list_size > 6 && index < list_size && pushed < (list_size / 2))
// 	{
// 		if (stack->a->num <= mid_node(&stack->a))
// 		{
// 			push(&stack->a, &stack->b, "pb");
// 			pushed++;
// 		}
// 		else
// 			rotate(&stack->a, "ra");
// 		index++;
// 	}
// 	while ((list_size - pushed) > 3)
// 	{
// 		push(&stack->a, &stack->b, "pb");
// 		pushed++;
// 	}
// }

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
