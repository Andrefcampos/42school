/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:18:48 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/12 18:21:05 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	delete_textures(t_content *content)
{
	mlx_delete_texture(content->floor_png);
	mlx_delete_texture(content->wall_png);
	mlx_delete_texture(content->person_png);
	mlx_delete_texture(content->coin_png);
	mlx_delete_texture(content->end_png);
}

void	delete_images(mlx_t *mlx, t_content *content)
{
	mlx_delete_image(mlx, content->floor_img);
	mlx_delete_image(mlx, content->wall_img);
	mlx_delete_image(mlx, content->person_img);
	mlx_delete_image(mlx, content->coin_img);
	mlx_delete_image(mlx, content->end_img);
}

void	free_matrix(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

int	free_end_game(t_data *data)
{
	delete_textures(data->content);
	delete_images(data->mlx, data->content);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	free_matrix(data->map->matrix);
	exit (EXIT_SUCCESS);
}
