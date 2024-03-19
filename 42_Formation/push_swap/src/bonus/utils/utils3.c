/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:43:04 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/18 20:06:00 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	size_list(t_node **head)
{
	int		index;
	t_node	*temp;

	index = 0;
	if (!*head)
		return (index);
	temp = *head;
	while (temp)
	{
		index++;
		temp = temp->next;
	}
	return (index);
}
