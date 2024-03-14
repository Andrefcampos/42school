/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/14 16:43:47 by andrefil         ###   ########.fr       */
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
		swap(&(*stack)->a, "sa");
	else if (ac == 4)
		sort_three(&(*stack)->a, 3);
	else if (ac == 5)
		sort_four(stack);
	else if (ac == 6)
		sort_five(stack);
	else
		sort_a(stack, &count, (*stack)->size_a);
}

void	sort_three(t_node **head, int size)
{
	int	big;

	big = max_node(head, size);
	if ((*head)->num == big)
		rotate(head, "ra");
	else if ((*head)->next->num == big)
		reverse_rotate(head, "rra");
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
	if (check_sort(&(*stack)->a) && !(*stack)->b)
		return ;
	push(stack, "pb");
	sort_three(&(*stack)->a, 3);
	push(stack, "pa");
}

void	sort_five(t_stack **stack)
{
	int	small;

	small = min_node(&(*stack)->a, (*stack)->size_a);
	if ((*stack)->a->next->num == small)
		swap(&(*stack)->a, "sa");
	else if ((*stack)->a->next->next->num == small)
		list_iter(&(*stack)->a, "ra", rotate, 2);
	else if ((*stack)->a->next->next->next->num == small)
		list_iter(&(*stack)->a, "rra", reverse_rotate, 2);
	else if ((*stack)->a->next->next->next->next->num ==  small)
		reverse_rotate(&(*stack)->a, "rra");
	if (check_sort(&(*stack)->a) && !(*stack)->b)
		return ;
	push(stack, "pb");
	sort_four(stack);
	push(stack, "pa");
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
			stack_iter(stack, "pa", push, size);
			return ;
		}
	}
	sort_all(stack, 'A', ((size / 2) + (size % 2)));
	sort_all(stack, 'B', (size / 2));
}

//void	sort_handler(t_stacks **stacks, int flag, int size)
//{
//	if (check_handler(stacks, flag, size))
//		return ;
//	if (flag == STACK_A)
//	{
//		if (!stack_sorted((*stacks)->a, flag, size))
//			sort_stack_a(stacks, size);
//		else
//			return ;
//	}
//	else
//	{
//		if (!stack_sorted((*stacks)->b, flag, size))
//			sort_stack_b(stacks, size);
//		else
//		{
//			push(stacks, STACK_A, size);
//			return ;
//		}
//	}
//	sort_handler(stacks, STACK_A, (size / 2) + (size % 2));
//	sort_handler(stacks, STACK_B, (size / 2));
//}
