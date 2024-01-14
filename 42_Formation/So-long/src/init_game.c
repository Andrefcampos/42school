/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:51:28 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/13 20:07:02 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_data *data)
{
	data->mlx = mlx_init((SIZE_IMG * data->map->count_cols),
			(SIZE_IMG * data->map->count_rows), "so-long (andrefil)", true);
	convert_png_to_texture(data->content);
	convert_texture_to_image(data->mlx, data->content);
	resize_image(data->content);
	validation_images(data->content);
	render_hook_map(data);
	mlx_key_hook(data->mlx, &move_player, data);
	mlx_loop_hook(data->mlx, &close_window, data);
	mlx_loop(data->mlx);
}
