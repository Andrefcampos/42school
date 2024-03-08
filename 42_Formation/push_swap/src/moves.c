/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:49:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/07 19:48:40 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

void	swap_first_last_node(t_node **head)
{
	t_node *first;
	t_node *second;
	t_node *last;

  if (*head == NULL || (*head)->next == NULL)
    return;
  first = *head;
  last = *head;
  second = last->next;
  while (last->next != NULL) {
    first->prev = last;
    last = last->next;
  }
  last->next = first;
  first->next = NULL;
  second->prev = NULL;
  *head = second;
}

void swap_first_second_node(t_node **head) {
  t_node *first;
  t_node *second;

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

void swap_last_first_node(t_node **head) {
  t_node *first;
  t_node *last;
  t_node *second_last;

  if (*head == NULL || (*head)->next == NULL)
    return;
  first = *head;
  last = *head;
  second_last = NULL;
  while (last->next != NULL) {
    second_last = last;
    last = last->next;
  }
  last->next = first;
  first->prev = last;
  last->prev = NULL;
  second_last->next = NULL;
  *head = last;
}

void	send_in_list(t_node **stack1, t_node **stack2)
{
	t_node	*first_stack1;
	t_node	*current_node;

	if (*stack1 == NULL || stack2 == NULL)
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

void	swap_second_last_node(t_node **head)
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
	//printf("swap first to last list :\n");
}
