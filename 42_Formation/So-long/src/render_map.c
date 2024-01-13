/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:01:29 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/11 20:05:26 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	position_person(t_data *data)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (data->map->matrix[y])
	{
		x = 0;
		while (data->map->matrix[y][x])
		{
			if (data->map->matrix[y][x] == 'P')
			{
				data->posix->y_plyr = y;
				data->posix->x_plyr = x;
			}
			if (data->map->matrix[y][x] == 'E')
			{
				data->posix->y_end = y;
				data->posix->x_end = x;
			}
			x++;
		}
		y++;
	}
}
