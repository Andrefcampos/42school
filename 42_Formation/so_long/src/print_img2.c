/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:58:31 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/14 05:13:42 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_floor(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->floor_img, x, y);
}

void	print_tile(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->tile_img, x, y);
}

void	print_wall(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->wall_img, x, y);
}
