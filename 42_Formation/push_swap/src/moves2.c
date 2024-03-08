/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:29:52 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/07 22:10:23 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	rotate_all_stack(t_node **head)
{
	t_node	*upd;
	t_node	*temp;
	
	if (!*head || !(*head)->next)
		return ;
	temp = *head;
	upd = NULL;
	while (temp)
		send_in_list(&temp, &upd);
	*head = upd;
}
