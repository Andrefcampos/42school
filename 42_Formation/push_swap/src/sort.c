/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/15 11:13:38 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	push_swap(int ac, t_stack **stack)
{
	int	count;

	if (check_sort(&(*stack)->a))
		return ;
	count = 0;
	if (ac == 3)
		swap(stack, "sa");
	else if (ac == 4)
		sort_three(stack);
	else if (ac == 5)
		sort_four(stack);
	else if (ac == 6)
		sort_five(stack);
	else
		sort_a(stack, &count, (*stack)->size_a);
}

void	sort_three(t_stack **stack)
{
	int	big;

	big = max_node(&(*stack)->a, 3);
	if ((*stack)->a->num == big)
		rotate(stack, "ra");
	else if ((*stack)->a->next->num == big)
		reverse_rotate(stack, "rra");
	if ((*stack)->a->num > (*stack)->a->next->num)
		swap(stack, "sa");
}

void	sort_four(t_stack **stack)
{
	int	small;

	small = min_node(&(*stack)->a, size_list(&(*stack)->a));
	if ((*stack)->a->next->num == small)
		swap(stack, "sa");
	else if ((*stack)->a->next->next->num == small)
		stack_iter(stack, "ra", rotate, 2);
	else if ((*stack)->a->next->next->next->num ==  small)
		reverse_rotate(stack, "rra");
	if (check_sort(&(*stack)->a) && !(*stack)->b)
		return ;
	push(stack, "pb");
	sort_three(stack);
	push(stack, "pa");
}

void	sort_five(t_stack **stack)
{
	int	small;

	small = min_node(&(*stack)->a, (*stack)->size_a);
	if ((*stack)->a->next->num == small)
		swap(stack, "sa");
	else if ((*stack)->a->next->next->num == small)
		stack_iter(stack, "ra", rotate, 2);
	else if ((*stack)->a->next->next->next->num == small)
		stack_iter(stack, "rra", reverse_rotate, 2);
	else if ((*stack)->a->next->next->next->next->num ==  small)
		reverse_rotate(stack, "rra");
	if (check_sort(&(*stack)->a) && !(*stack)->b)
		return ;
	push(stack, "pb");
	sort_four(stack);
	push(stack, "pa");
}

void	sort_stacks(t_stack **stack, char c, int size)
{
	if (check_sort_stacks(stack, c, size))
		return ;
	if (c == 'A')
	{
		if (!check_n_sort(&(*stack)->a, c, size))
			sort_stack_a(stack, size);
		else
			return ;
	}
	else
	{
		if (!check_n_sort(&(*stack)->b, c, size))
			sort_stack_b(stack, size);
		else
		{
			stack_iter(stack, "pa", push, size);
			return ;
		}
	}
	sort_stacks(stack, 'A', ((size / 2) + (size % 2)));
	sort_stacks(stack, 'B', (size / 2));
}
