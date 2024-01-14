/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:20:10 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/13 23:58:25 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(mlx_key_data_t keyd, void *param)
{
	t_data	*data;
	int32_t	x;
	int32_t	y;

	data = (t_data *)param;
	data->posix->x_plyr = data->content->player_img->instances->x / TILE_SIZE;
	data->posix->y_plyr = data->content->player_img->instances->y / TILE_SIZE;
	x = data->posix->x_plyr;
	y = data->posix->y_plyr;
	if (keyd.key == MLX_KEY_W && keyd.action == MLX_PRESS
		&& data->map->matrix[y - 1][x] != '1')
		up_move(data, x, y);
	if (keyd.key == MLX_KEY_A && keyd.action == MLX_PRESS
		&& data->map->matrix[y][x - 1] != '1')
		left_move(data, x, y);
	if (keyd.key == MLX_KEY_S && keyd.action == MLX_PRESS
		&& data->map->matrix[y + 1][x] != '1')
		down_move(data, x, y);
	if (keyd.key == MLX_KEY_D && keyd.action == MLX_PRESS
		&& data->map->matrix[y][x + 1] != '1')
		right_move(data, x, y);
}

void	put_elements_map(t_data *data, int32_t cols, int32_t rows)
{
	print_floor(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
	if (data->map->matrix[rows][cols] == '0')
		print_tile(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
	if (data->map->matrix[rows][cols] == '1')
		print_wall(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
	if (data->map->matrix[rows][cols] == 'C')
	{
		print_tile(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
		print_bone(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
	}
	if (data->map->matrix[rows][cols] == 'P')
	{
		print_tile(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
		print_player(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
	}
	if (data->map->matrix[rows][cols] == 'E')
	{
		print_tile(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
		print_exit(data, (SIZE_IMG * cols), (SIZE_IMG * rows));
	}
}

void	render_hook_map(t_data *data)
{
	int32_t	x;
	int32_t	y;

	if (data->mlx == NULL)
		return ;
	y = 0;
	while (y < data->map->count_rows)
	{
		x = 0;
		while (x < data->map->count_cols)
		{
			put_elements_map(data, x, y);
			x++;
		}
		y++;
	}
}

void	close_window(void *key)
{
	t_data	*data;

	data = (t_data *)key;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		free_end_game(data);
}
