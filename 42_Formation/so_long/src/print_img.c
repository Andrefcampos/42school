/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:20:07 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/14 05:13:47 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_player(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->player_img, x, y);
}

void	print_exit(t_data *data, int32_t x, int32_t y)
{
	data->content->end_img->enabled = false;
	mlx_image_to_window(data->mlx, data->content->end_img, x, y);
}

void	print_bone(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->bone_img, x, y);
}
