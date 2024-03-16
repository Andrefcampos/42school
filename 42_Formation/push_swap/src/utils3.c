/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:52:32 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/15 18:22:00 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	send_first_to_last(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
    	return;
	first = *head;
	last = *head;
	second = last->next;
	while (last->next != NULL)
	{
		first->prev = last;
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	second->prev = NULL;
	*head = second;
}

void	swap_first_second_node(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (*head == NULL || (*head)->next == NULL)
		return;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*head = second;
	if (first->next != NULL)
		first->next->prev = first;
}

void	send_in_list(t_node **stack1, t_node **stack2)
{
	t_node	*first_stack1;
	t_node	*current_node;

	if (*stack1 == NULL || stack1 == NULL)
		return;
	if ((*stack1)->next == NULL)
	{
		list_add_next_first(stack2, *stack1);
		*stack1 = NULL;
		return;
	}
	first_stack1 = *stack1;
	current_node = first_stack1;
	first_stack1 = first_stack1->next;
	first_stack1->prev = NULL;
	*stack1 = first_stack1;
	current_node->next = NULL;
	current_node->prev = NULL;
	if (!*stack2)
	{
		*stack2 = current_node;
		return;
	}
	list_add_next_first(stack2, current_node);
}

void	list_iter(t_node **lst, char *s, \
		void (*f)(t_node **, char *), int size)
{
	while (size--)
		(*f)(lst, s);
}

void	stacks_iter(t_node **lst1, t_node **lst2, \
		void (*f)(t_node **, t_node **), int size)
{
	while (size--)
		(*f)(lst1, lst2);
}

void	stack_iter(t_stack **stack, char *move, \
		void (*f)(t_stack **, char *), int size)
{
	while (size--)
		(*f)(stack, move);
}
