/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:20:07 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/12 11:33:56 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_floor(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->floor_img, x, y);
}

void	print_wall(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->wall_img, x, y);
}

void	print_bone(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->coin_img, x, y);
}

void	print_player(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->person_img, x, y);
}

void	print_exit(t_data *data, int32_t x, int32_t y)
{
	data->content->end_img->enabled = false;
	mlx_image_to_window(data->mlx, data->content->end_img, x, y);
}
