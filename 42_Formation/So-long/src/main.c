/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:48:13 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/12 18:25:53 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_data	*ft_pointer_data(void)
{
	static t_data	data;
	return(&data);
}

t_map	*ft_pointer_map(void)
{
	static t_map	map;
	return (&map);
}

t_content	*ft_pointer_content(void)
{
	static t_content	content;
	return (&content);
}

t_posix	*ft_pointer_pos(void)
{
	static t_posix	pos_elem;
	return (&pos_elem);
}

int32_t	main(int argc, char **argv)
{
	t_data	*game;

	game = ft_pointer_data();
	game->map = ft_pointer_map();
	game->content = ft_pointer_content();
	game->posix = ft_pointer_pos();

	read_file(argv[1], game->map);
	build_matrix(game->map);

	position_person(game);
	init_game(game);
	free_end_game(game);
	return (EXIT_SUCCESS);
}
