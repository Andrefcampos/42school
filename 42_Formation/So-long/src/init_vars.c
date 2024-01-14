/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 03:17:11 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/14 05:43:35 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_map	*ft_pointer_map(void)
{
	static t_map	map;

	return (&map);
}

static t_content	*ft_pointer_content(void)
{
	static t_content	content;

	return (&content);
}

static t_posix	*ft_pointer_pos(void)
{
	static t_posix	pos_elem;

	return (&pos_elem);
}

void	init_vars(t_data *data)
{
	data->map = ft_pointer_map();
	data->content = ft_pointer_content();
	data->posix = ft_pointer_pos();
	data->map->read_bytes = 1;
	data->map->size_map = 0;
	data->map->count_cols = 0;
	data->map->count_rows = 0;
	data->map->count_bone = 0;
	data->map->count_person = 0;
	data->map->count_end = 0;
}
