/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:03:47 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/12 20:42:09 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_elements(t_map *map)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	map->count_coin = 0;
	map->count_person = 0;
	map->count_end = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x] != '\0')
		{
			if (map->matrix[y][x] == 'P')
				map->count_person++;
			if (map->matrix[y][x] == 'C')
				map->count_coin++;
			if (map->matrix[y][x] == 'E')
				map->count_end++;
			x++;
		}
		y++;
	}
}

int	check_wall_map(t_map *map)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x] != '\0')
		{
			if (map->matrix[0][x] != '1'
				|| map->matrix[map->count_rows - 1][x] != '1'
				|| map->matrix[y][0] != '1'
				|| map->matrix[y][map->count_cols - 1] != '1')
			{
				free(map->matrix);
				ft_printf("Invalid element in map.\n");
				exit (EXIT_FAILURE);
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
		ft_printf("ERROR. Invalid map (exceeds allowed newline limit).");
		free(buffer);
		exit (EXIT_FAILURE);
	}
	while (buffer[index] != '\0')
	{
		if ((buffer[index] == '\n' && buffer[index - 1] != '1')
			|| (buffer[index] == '\n' && buffer[index + 1] == '\n'))
		{
			ft_printf("ERROR. Invalid map (exceeds allowed newline limit).");
			free(buffer);
			exit (EXIT_FAILURE);
		}
		index++;
	}
	return (EXIT_SUCCESS);
}
