/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:58:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/11 09:41:32 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdio.h>

t_node	*create_node(int data)
{
	t_node	*set;

	set = ft_calloc(1, sizeof(t_node));
	if (!set)
		return (NULL);
	set->num = data;
	set->prev = NULL;
	set->next = NULL;
	return (set);
}

void	list_add_next_last(t_node **head, t_node *new_node)
{
	t_node	*upd;
	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	upd = *head;
	while (upd->next)
		upd = upd->next;
	new_node->prev = upd;
	upd->next = new_node;
}

void	list_add_next_first(t_node **head, t_node *new_node)
{
	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	new_node->next = *head;
	(*head)->prev = new_node;
	if (new_node->prev != NULL)
		new_node->prev = NULL;
	*head = new_node;
}

void send_last_to_first(t_node **head)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;
 
	if (*head == NULL || (*head)->next == NULL)
		return;
	first = *head;
	last = *head;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	second_last->next = NULL;
	*head = last;
}

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
