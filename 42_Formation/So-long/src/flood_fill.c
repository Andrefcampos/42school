/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:31:31 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/14 06:19:14 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill_help(t_map *map, char **matrix, int x, int y)
{
	if (x < 0 || x >= map->count_cols - 1 || y < 0 || y >= map->count_rows - 1
		|| matrix[y][x] == '1')
		return ;
	matrix[y][x] = '1';
	flood_fill_help(map, matrix, x + 1, y);
	flood_fill_help(map, matrix, x - 1, y);
	flood_fill_help(map, matrix, x, y + 1);
	flood_fill_help(map, matrix, x, y - 1);
}

static int	char_is_valid(char c)
{
	return (c == 'P' || c == 'E' || c == 'C');
}

static int	check_flood_fill(char **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x] != '\0')
		{
			if (char_is_valid(matrix[y][x]))
			{
				return (EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

void	free_allocations(char *buffer, char **matrix)
{
	free_matrix(matrix);
	free(buffer);
	exit (EXIT_FAILURE);
}

void	ft_flood_fill(t_data *data)
{
	char	**matrix;
	int		x;
	int		y;

	y = 0;
	matrix = ft_split(data->map->buffer, '\n');
	check_format_map(data->map, matrix);
	position_player(data->posix, matrix);
	count_elements(data->map, matrix);
	if (data->map->count_person != 1 || data->map->count_end != 1
		|| data->map->count_bone < 1)
	{
		ft_printf("ERROR. Invalid map (incorrect quantities of elements).\n");
		free_allocations(data->map->buffer, matrix);
	}
	check_wall_map(data->map, matrix);
	flood_fill_help(data->map, matrix, data->posix->x_plyr, \
		data->posix->y_plyr);
	if (check_flood_fill(matrix) == EXIT_FAILURE)
	{
		ft_printf("ERROR. Invalid map (elements blocked by walls).\n");
		free_allocations(data->map->buffer, matrix);
	}
	free_matrix(matrix);
}
