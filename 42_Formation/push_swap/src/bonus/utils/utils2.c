/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:30:33 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/18 20:05:37 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h> //TODO: apagar depois

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

void	send_first_to_last(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
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
		return ;
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
		return ;
	if ((*stack1)->next == NULL)
	{
		list_add_next_first(stack2, *stack1);
		*stack1 = NULL;
		return ;
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
		return ;
	}
	list_add_next_first(stack2, current_node);
}

// TODO: delete function:
void	print_list(t_node **list)
{
	t_node	*temp;

	if (!*list)
		return ;
	temp = *list;
	while (temp)
	{
		printf("nó: %d\n", temp->num);
		temp = temp->next;
	}
}
