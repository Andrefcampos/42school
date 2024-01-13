/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:41:28 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/12 18:26:28 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	next_step(t_data *data, int32_t x, int32_t y)
{
	data->map->matrix[data->posix->y_plyr][data->posix->x_plyr] = '0';
	render_start_player(data->mlx, data->content, x, y);
	ft_printf("Moves: %d\n", ++data->move);
	if (data->map->matrix[y][x] == 'C')
	{
		data->map->count_coin--;
		data->map->matrix[y][x] = '0';
		print_floor(data, (x * WIDTH_IMG), (y * HEIGHT_IMG));
		print_player(data, (x * WIDTH_IMG), (y * HEIGHT_IMG));
	}
	if (data->map->count_coin == 0)
	{
		data->map->matrix[data->posix->y_end][data->posix->x_end] = 'E';
		data->content->end_img->enabled = true;
		if (data->map->matrix[y][x] == 'E')
		{
			ft_printf("You collect all bones and finish game.\n");
			free_end_game(data);
		}
	}
	data->map->matrix[y][x] = 'P';
}

void	up_movement(t_data *data, int32_t move_x, int32_t move_y)
{
	int32_t	x;
	int32_t	y;

	x = move_x;
	y = move_y - 1;
	if (data->map->matrix[y][x] != '1')
	{
		next_step(data, x, y);
		move_y--;
	}
}

void	left_movement(t_data *data, int32_t move_x, int32_t move_y)
{
	int32_t	x;
	int32_t	y;

	x = move_x - 1;
	y = move_y;
	if (data->map->matrix[y][x] != '1')
	{
		next_step(data, x, y);
		move_x--;
	}
}

void	down_movement(t_data *data, int32_t move_x, int32_t move_y)
{
	int32_t	x;
	int32_t	y;

	x = move_x;
	y = move_y + 1;
	if (data->map->matrix[y][x] != '1')
	{
		next_step(data, x, y);
		move_y++;
	}
}

void	right_movement(t_data *data, int32_t move_x, int32_t move_y)
{
	int32_t	x;
	int32_t	y;

	x = move_x + 1;
	y = move_y;
	if (data->map->matrix[y][x] != '1')
	{
		next_step(data, x, y);
		move_x++;
	}
}
