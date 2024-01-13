/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:09:15 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/12 20:53:19 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int32_t	open_file(const char *argv)
{
	int32_t	fd;

	fd = open(argv, O_RDONLY, 0666);
	if (fd < 0)
	{
		ft_printf("ERROR. Invalid fd (%d).\n", fd);
		close(fd);
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

static void	count_elements_map(t_map *map)
{
	int	index;
	int	cols;

	index = 0;
	cols = 0;
	map->count_cols = 0;
	map->count_rows = 0;
	while (map->buffer[index] != '\0')
	{
		if (map->buffer[index] == '1' || map->buffer[index] == '0'
			|| map->buffer[index] == 'C' || map->buffer[index] == 'E'
			|| map->buffer[index] == 'P')
			cols++;
		if (index > 0 && (map->buffer[index - 1] == '1' && map->buffer[index] == '\n'
			&& map->buffer[index + 1] == '1'))
			map->count_rows++;
		index++;
	}
	map->count_rows++;
	map->count_cols = cols / map->count_rows;
}

void	read_file(const char *argv, t_map *map)
{
	map->fd = open_file(argv);
	map->read_bytes = 1;
	map->size_map = 0;
	while (map->read_bytes > 0)
	{
		map->read_bytes = read(map->fd, &map->c, 1);
		if (check_char_str(map->c, "\n01CEP") != 0)
			exit (EXIT_FAILURE);
		map->size_map++;
	}
	close(map->fd);
	map->fd = open_file(argv);
	map->buffer = ft_calloc(map->size_map + 1, sizeof(char));
	if (!map->buffer)
	{
		free (map->buffer);
		ft_printf("ERROR in alocate map in buffer.\n");
		exit (EXIT_FAILURE);
	}
	map->read_bytes = read(map->fd, map->buffer, map->size_map);
	close(map->fd);
}

void	build_matrix(t_map *map)
{
	check_newlines_map(map->buffer);
	count_elements_map(map);
	if (map->size_map < 17)
	{
		ft_printf("ERROR. Invalid map in map (map size smaller than the minimum possible).\n");
		exit(EXIT_FAILURE);
	}
	map->matrix = ft_split(map->buffer, '\n');
	check_wall_map(map);
	free(map->buffer);
	count_elements(map);
	if (map->count_person != 1 || map->count_end != 1
		|| map->count_coin < 1)
	{
		printf("ERROR. Invalid map (incorrect quantities of elements).");
		exit (ERROR);
	}
}
