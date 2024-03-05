/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:58:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/04 20:34:55 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

t_node	*create_node(int data)
{
	t_node	*set;

	set = malloc(sizeof(t_list));
	if (!set)
		return (NULL);
	set->num = data;
	set->prev = NULL;
	set->next = NULL;
	return (set);
}

void	add_next_last(t_node **head, t_node *new_node)
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

void	add_next_front(t_node **head, t_node *new_node)
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

void	del_one_node(t_node **head, int val)
{
	t_node	*temp;

	if (!*head || (*head)->next == NULL)
		return ;
	temp = *head;
	while (temp && temp->num != val)
		temp = temp->next;
	if (temp == NULL)
		return ;
	if (temp == *head)
		*head = temp->next;
	if (temp->prev != NULL)
		temp->prev->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = temp->prev;
	free(temp);
//	ft_printf("\nDel one element in list:\n");
}

