/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:35:30 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/18 17:49:53 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

t_llist	*ft_llstnew(char c)
{
	t_llist	*new_node;

	new_node = (t_llist *)malloc(sizeof(t_llist));
	new_node->content = c;
	new_node->next = NULL;
	return (new_node);
}

void	ft_llstadd_back(t_llist **lst, t_llist *new)
{
	t_llist	*last;

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

void	*ft_llstclear(t_llist **lst)
{
	t_llist	*tmp;

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
