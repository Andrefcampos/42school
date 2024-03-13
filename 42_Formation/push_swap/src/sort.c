/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 19:47:47 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	push_swap(int ac, t_stack *stack)
{
	int	count;

	count = 0;
	if (ac < 5)
		sort_three(&stack->a);
	else if (ac < 6)
		sort_four(&stack);
	else if (ac < 7)
		sort_five(&stack);
	else
		sort_a(&stack, &count, size_list(&stack->a));
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

void	sort_four(t_stack **stack)
{
	int	small;

	small = min_node(&(*stack)->a, size_list(&(*stack)->a));
	if ((*stack)->a->next->num == small)
		swap(&(*stack)->a, "sa");
	else if ((*stack)->a->next->next->num == small)
		list_iter(&(*stack)->a, "ra", rotate, 2);
	else if ((*stack)->a->next->next->next->num ==  small)
		reverse_rotate(&(*stack)->a, "rra");
	check_sort(&(*stack)->a);
	push(&(*stack)->a, &(*stack)->b, "pb");
	sort_three(&(*stack)->a);
	push(&(*stack)->b, &(*stack)->a, "pa");
}

void	sort_five(t_stack **stack)
{
	int	small;

	small = min_node(&(*stack)->a, size_list(&(*stack)->a));
	if ((*stack)->a->next->num == small)
		swap(&(*stack)->a, "sa");
	else if ((*stack)->a->next->next->num == small)
		list_iter(&(*stack)->a, "ra", rotate, 2);
	else if ((*stack)->a->next->next->next->num == small)
		list_iter(&(*stack)->a, "rra", reverse_rotate, 2);
	else if ((*stack)->a->next->next->next->next->num ==  small)
		reverse_rotate(&(*stack)->a, "rra");
	check_sort(&(*stack)->a);
	push(&(*stack)->a, &(*stack)->b, "pb");
	sort_three(&(*stack)->a);
	push(&(*stack)->b, &(*stack)->a, "pa");
}

void	sort_all(t_stack **stack, char c, int size)
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
			push(&(*stack)->b, &(*stack)->a, "pb");
			return ;
		}
	}
	sort_all(stack, 'A', ((size / 2) + (size % 2)));
	sort_all(stack, 'B', (size / 2));
}
