/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:27:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/14 02:17:16 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	convert_png_to_texture(t_content *content)
{
	content->floor_png = mlx_load_png(FLOOR);
	content->tile_png = mlx_load_png(TILE);
	content->wall_png = mlx_load_png(WALL);
	content->bone_png = mlx_load_png(BONE);
	content->player_png = mlx_load_png(PLAYER_R);
	content->end_png = mlx_load_png(END);
	if (!content->floor_png
		|| !content->tile_png
		|| !content->wall_png
		|| !content->bone_png
		|| !content->player_png
		|| !content->end_png)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	convert_texture_to_image(mlx_t *mlx, t_content *content)
{
	content->floor_img = mlx_texture_to_image(mlx, content->floor_png);
	content->tile_img = mlx_texture_to_image(mlx, content->tile_png);
	content->wall_img = mlx_texture_to_image(mlx, content->wall_png);
	content->bone_img = mlx_texture_to_image(mlx, content->bone_png);
	content->player_img = mlx_texture_to_image(mlx, content->player_png);
	content->end_img = mlx_texture_to_image(mlx, content->end_png);
}

void	resize_image(t_content *content)
{
	mlx_resize_image(content->floor_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->tile_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->wall_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->bone_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->player_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->end_img, SIZE_IMG, SIZE_IMG);
}

void	render_move_player(t_data *data, int32_t col, int32_t row)
{
	if (data->content->side_player == 0)
	{
		mlx_delete_image(data->mlx, data->content->player_img);
		mlx_delete_texture(data->content->player_png);
		data->content->player_png = mlx_load_png(PLAYER_R);
		data->content->player_img = mlx_texture_to_image(data->mlx, \
			data->content->player_png);
		mlx_resize_image(data->content->player_img, SIZE_IMG, SIZE_IMG);
		mlx_image_to_window(data->mlx, data->content->player_img, \
			(SIZE_IMG * col), (SIZE_IMG * row));
	}
	else if (data->content->side_player == 1)
	{
		mlx_delete_image(data->mlx, data->content->player_img);
		mlx_delete_texture(data->content->player_png);
		data->content->player_png = mlx_load_png(PLAYER_L);
		data->content->player_img = mlx_texture_to_image(data->mlx, \
			data->content->player_png);
		mlx_resize_image(data->content->player_img, SIZE_IMG, SIZE_IMG);
		mlx_image_to_window(data->mlx, data->content->player_img, \
			(SIZE_IMG * col), (SIZE_IMG * row));
	}
}

void	validation_images(t_content *content)
{
	if (content->floor_img == NULL || content->tile_img == NULL \
		|| content->wall_img == NULL || content->bone_img == NULL \
		|| content->player_img == NULL || content->end_img == NULL)
		ft_printf("Image loading failed!\n");
}
