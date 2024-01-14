/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:48:13 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/14 06:12:49 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_data	*ft_pointer_game(void)
{
	static t_data	game;

	return (&game);
}

static void	check_args(const char *argv, char *str)
{
	int	len_arg;
	int	len_str;

	len_arg = (int)ft_strlen(argv);
	len_str = (int)ft_strlen(str);
	while (len_str >= 0)
	{
		if (argv[len_arg] != str[len_str])
		{
			ft_printf("%c\n", argv[len_arg]);
			ft_printf("ERROR. file: %s Invalid extension.\n", argv);
			exit (EXIT_FAILURE);
		}
		len_arg--;
		len_str--;
	}
}

int32_t	main(int argc, char **argv)
{
	t_data	*game;

	if (argc != 2)
	{
		ft_printf("ERROR. Invalid quantities files.\n");
		exit (EXIT_FAILURE);
	}
	check_args(argv[1], ".ber");
	game = ft_pointer_game();
	init_vars(game);
	build_matrix(game, argv[1]);
	init_game(game);
	free_end_game(game);
	return (EXIT_SUCCESS);
}
