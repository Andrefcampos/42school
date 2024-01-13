/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:27:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/12 15:04:33 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	convert_png_to_texture(t_content *content)
{
	content->floor_png = mlx_load_png("./images/floor.png");
	content->wall_png = mlx_load_png("./images/wall.png");
	content->coin_png = mlx_load_png("./images/coin.png");
	content->person_png = mlx_load_png("./images/person.png");
	content->end_png = mlx_load_png("./images/end.png");
	if (!content->floor_png
		|| !content->wall_png
		|| !content->coin_png
		|| !content->person_png
		|| !content->end_png)
		return (ERROR);
	return (VALIDATE);
}

void	convert_texture_to_image(mlx_t *mlx, t_content *content)
{
	content->floor_img = mlx_texture_to_image(mlx, content->floor_png);
	content->wall_img = mlx_texture_to_image(mlx, content->wall_png);
	content->coin_img = mlx_texture_to_image(mlx, content->coin_png);
	content->person_img = mlx_texture_to_image(mlx, content->person_png);
	content->end_img = mlx_texture_to_image(mlx, content->end_png);
}

void	resize_image(t_content *content)
{
	mlx_resize_image(content->floor_img, WIDTH_IMG, HEIGHT_IMG);
	mlx_resize_image(content->wall_img, WIDTH_IMG, HEIGHT_IMG);
	mlx_resize_image(content->coin_img, WIDTH_IMG, HEIGHT_IMG);
	mlx_resize_image(content->person_img, WIDTH_IMG, HEIGHT_IMG);
	mlx_resize_image(content->end_img, WIDTH_IMG, HEIGHT_IMG);
}

void	render_start_player(mlx_t *mlx,
		t_content *content, int32_t col, int32_t row)
{
	int32_t	x;
	int32_t	y;

	x = WIDTH_IMG;
	y = HEIGHT_IMG;
	mlx_delete_image(mlx, content->person_img);
	mlx_delete_texture(content->person_png);
	content->person_png = mlx_load_png("./images/person.png");
	content->person_img = mlx_texture_to_image(mlx, content->person_png);
	mlx_resize_image(content->person_img, x, y);
	mlx_image_to_window(mlx, content->person_img, (x * col), (y * row));
}

void	validation_images(t_content *content)
{
	if (content->floor_img == NULL || content->wall_img == NULL
		|| content->coin_img == NULL || content->person_img == NULL
		|| content->end_img == NULL)
		ft_printf("Image loading failed!\n");
}
