/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:35:30 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/17 21:26:49 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnlvars	*gnl_lstnew(char c)
{
	t_gnlvars	*new_node;

	new_node = (t_gnlvars *)malloc(sizeof(t_gnlvars));
	new_node->content = c;
	new_node->next = NULL;
	return (new_node);
}

void	gnl_lstadd_back(t_gnlvars **lst, t_gnlvars *new)
{
	t_gnlvars	*last;

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

void	*gnl_lstclear(t_gnlvars **lst)
{
	t_gnlvars	*tmp;

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
