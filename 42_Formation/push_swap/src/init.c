/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:23:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/08 17:20:01 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

void	init_data(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return ;
	(*data)->a = NULL;
	(*data)->b = NULL;
	(*data)->max_a = max_node(&(*data)->a);
	(*data)->min_a = min_node(&(*data)->a);
	(*data)->max_b = 0;
	(*data)->min_b = 0;
	(*data)->moves = 0;
}
