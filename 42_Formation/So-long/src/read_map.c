/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:09:15 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/14 10:19:00 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int32_t	open_file(const char *av)
{
	int32_t	fd;

	fd = open(av, O_RDONLY, 0666);
	if (fd < 0)
	{
		ft_printf("ERROR. Invalid fd (%d).\n", fd);
		exit (EXIT_FAILURE);
	}
	return (fd);
}

static int	check_char_str(char c, char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (c == str[index])
			return (EXIT_SUCCESS);
		index++;
	}
	return (EXIT_FAILURE);
}

static void	check_dimensions_map(t_map *map)
{
	int	index;
	int	cols;

	index = 0;
	cols = 0;
	while (map->buffer[index] != '\0')
	{
		if (map->buffer[index] == '1' || map->buffer[index] == '0'
			|| map->buffer[index] == 'C' || map->buffer[index] == 'E'
			|| map->buffer[index] == 'P')
			cols++;
		if (index > 0 && (map->buffer[index - 1] == '1' \
			&& map->buffer[index] == '\n' \
			&& map->buffer[index + 1] == '1'))
			map->count_rows++;
		index++;
	}
	map->count_rows++;
	map->count_cols = cols / map->count_rows;
}

void	read_file(const char *av, t_map *map)
{
	map->fd = open_file(av);
	while (map->read_bytes > 0)
	{
		map->read_bytes = read(map->fd, &map->c, 1);
		if (check_char_str(map->c, "\n01CEP") != 0)
		{
			ft_printf("ERROR. Invalid map (NULL or invalid element).\n");
			exit (EXIT_FAILURE);
		}
		map->size_map++;
	}
	close(map->fd);
	map->fd = open_file(av);
	map->buffer = ft_calloc(map->size_map, sizeof(char));
	if (!map->buffer)
	{
		ft_printf("ERROR. Memory allocation failed.\n");
		exit (EXIT_FAILURE);
	}
	map->read_bytes = read(map->fd, map->buffer, map->size_map);
	close(map->fd);
}

void	build_matrix(t_data *data, const char *av)
{
	read_file(av, data->map);
	if (data->map->size_map < 17)
	{
		free (data->map->buffer);
		ft_printf("ERROR. Impossible map valid.\n");
		exit(EXIT_FAILURE);
	}
	check_newlines_map(data->map->buffer);
	check_dimensions_map(data->map);
	ft_flood_fill(data);
	data->map->matrix = ft_split(data->map->buffer, '\n');
	free(data->map->buffer);
}
