/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:30:33 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 04:17:37 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdio.h>

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

void	listcopy(t_node **head, t_node **s_dest)
{
	t_node *temp;

	if (!*head)
		return ;
	temp = *head;
	while (temp && temp->next != NULL)
	{
		list_add_next_last(s_dest, create_node(temp->num));
		temp = temp->next;
	}
}

void	listncopy(t_node **head, t_node **s_dest, int n)
{
	t_node *temp;

	if (!*head)
		return ;
	temp = *head;
	while (temp && --n)
	{
		list_add_next_last(s_dest, create_node(temp->num));
		temp = temp->next;
	}
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
	free (temp);
}

