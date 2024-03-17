/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:58:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/17 16:29:08 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdio.h>

t_node	*create_node(int stack)
{
	t_node	*set;

	set = ft_calloc(1, sizeof(t_node));
	if (!set)
		return (NULL);
	set->num = stack;
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

void	send_last_to_first(t_node **head)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (*head == NULL)
		return ;
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
