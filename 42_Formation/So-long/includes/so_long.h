/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:48:40 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/12 18:11:22 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# define WIDTH 512
# define HEIGHT 512
# define ERROR -1
# define VALIDATE 0
# define TILE_SIZE 32
# define WIDTH_IMG 32
# define HEIGHT_IMG 32

typedef struct s_positions_elements
{
	int32_t		x_end;
	int32_t		y_end;
	int32_t		x_plyr;
	int32_t		y_plyr;

}				t_posix;

typedef struct s_content
{
	mlx_texture_t		*floor_png;
	mlx_image_t			*floor_img;
	mlx_texture_t		*wall_png;
	mlx_image_t			*wall_img;
	mlx_texture_t		*coin_png;
	mlx_image_t			*coin_img;
	mlx_texture_t		*person_png;
	mlx_image_t			*person_img;
	mlx_texture_t		*enemy_png;
	mlx_image_t			*enemy_img;
	mlx_texture_t		*end_png;
	mlx_image_t			*end_img;
}						t_content;

typedef	struct s_map
{
	char		c;
	char		*buffer;
	char		**matrix;
	int32_t		read_bytes;
	int32_t		size_map;
	int32_t		count_rows;
	int32_t		count_cols;
	int32_t		count_person;
	int32_t		count_coin;
	int32_t		count_end;
	int32_t		fd;
}				t_map;

typedef struct s_data
{
	mlx_t			*mlx;
	t_content		*content;
	t_map			*map;
	t_posix			*posix;
	int32_t			move;
}					t_data;

//---------------- START GAME ----------------
void	init_game(t_data *data);
//------------------- MAP --------------------
void	read_file(const char *argv, t_map *map);
void	build_matrix(t_map *map);
void	render_map(t_data *data);
void	position_person(t_data *data);
void	count_elements(t_map *map);
int		check_wall_map(t_map *map);
int		check_newlines_map(char *buffer);
//----------------- IMAGE --------------------
int32_t	convert_png_to_texture(t_content *content);
void	convert_texture_to_image(mlx_t *mlx, t_content *content);
void	resize_image(t_content *content);
void	validation_images(t_content *content);

void	print_player(t_data *data, int32_t x, int32_t y);
void	print_floor(t_data *data, int32_t x, int32_t y);
void	print_wall(t_data *data, int32_t x, int32_t y);
void	print_bone(t_data *data, int32_t x, int32_t y);
void	print_exit(t_data *data, int32_t x, int32_t y);
//------------ MOVIMENTS PLAYER --------------
void	up_movement(t_data *data, int32_t move_x, int32_t move_y);
void	left_movement(t_data *data, int32_t move_x, int32_t move_y);
void	down_movement(t_data *data, int32_t move_x, int32_t move_y);
void	right_movement(t_data *data, int32_t move_x, int32_t move_y);
void	move_player(mlx_key_data_t keyd, void *param);
void	render_start_player(mlx_t *mlx, t_content *content, int32_t col, int32_t row);

void	render_hook_map(t_data *data);
void	put_elements_map(t_data *data, int32_t cols, int32_t rows);
//------------ FREE/CLOSE GAME ---------------
void	delete_textures(t_content *content);
void	delete_images(mlx_t *mlx, t_content *content);
void	free_matrix(char **matrix);
int		free_end_game(t_data *data);
void	close_window(void *key);

#endif
