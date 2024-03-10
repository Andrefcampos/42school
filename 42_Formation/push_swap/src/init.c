/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:23:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/10 05:30:21 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	init_data(t_data **data)
{
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return ;
	(*data)->a = NULL;
	(*data)->b = NULL;
	(*data)->min_a = 0;
	(*data)->max_a = 0;
	(*data)->max_b = 0;
	(*data)->min_b = 0;
	(*data)->moves = 0;
}
