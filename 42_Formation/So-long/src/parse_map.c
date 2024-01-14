/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:03:47 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/14 05:40:56 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_elements(t_map *map, char **matrix)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (matrix[y] != NULL)
	{
		x = 0;
		while (matrix[y][x] != '\0')
		{
			if (matrix[y][x] == 'P')
				map->count_person++;
			if (matrix[y][x] == 'C')
				map->count_bone++;
			if (matrix[y][x] == 'E')
				map->count_end++;
			x++;
		}
		y++;
	}
}

int	check_wall_map(t_map *map, char **matrix)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x] != '\0')
		{
			if (matrix[0][x] != '1'
				|| matrix[map->count_rows - 1][x] != '1'
				|| matrix[y][0] != '1'
				|| matrix[y][map->count_cols - 1] != '1')
			{
				ft_printf("ERROR.");
				ft_printf("wall elements are not in the required positions.\n");
				free_allocations(map->buffer, map->matrix);
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	check_newlines_map(char *buffer)
{
	int	index;

	index = 0;
	if (buffer[0] == '\n')
	{
		ft_printf("ERROR. Invalid map (exceeds allowed newline limit).\n");
		free(buffer);
		exit (EXIT_FAILURE);
	}
	while (buffer[index] != '\0')
	{
		if ((buffer[index] == '\n' && buffer[index - 1] != '1')
			|| (buffer[index] == '\n' && buffer[index + 1] == '\n'))
		{
			ft_printf("ERROR. Invalid map (exceeds allowed newline limit).\n");
			free(buffer);
			exit (EXIT_FAILURE);
		}
		index++;
	}
	return (EXIT_SUCCESS);
}

void	position_player(t_posix *posix, char **matrix)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'P')
			{
				posix->y_plyr = y;
				posix->x_plyr = x;
			}
			if (matrix[y][x] == 'E')
			{
				posix->y_end = y;
				posix->x_end = x;
			}
			x++;
		}
		y++;
	}
}

void	check_format_map(t_map *map, char **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
			x++;
		if (x != map->count_cols)
		{
			ft_printf("ERROR. Invalid map (not rectangular).\n");
			free_allocations(map->buffer, matrix);
		}
		y++;
	}
}
