/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:23:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/11 08:46:48 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	init_data(t_data **data, char **av)
{
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return ;
	create_list(av, &(*data)->a);
	(*data)->max_a = max_node(&(*data)->a);
	(*data)->size_a = size_stack(&(*data)->a);
	(*data)->min_a = min_node(&(*data)->a);
	(*data)->b = NULL;
	(*data)->size_b = 0;
	(*data)->min_b = 0;
	(*data)->max_b = 0;
	(*data)->moves = 0;
}
