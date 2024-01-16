/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:35:30 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/16 18:14:11 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char c)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	new_node->content = c;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	*ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp = tmp->next;
		free(*lst);
		*lst = tmp;
	}
	tmp = NULL;
	return (NULL);
}
