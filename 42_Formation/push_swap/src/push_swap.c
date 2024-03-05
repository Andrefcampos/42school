/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:06:53 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/05 15:52:18 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "libft.h"
//#include <stdio.h>

#include <stdlib.h>

int	check_args(char **av)
{
	int	y;
	int	x;

	y = 1;
	while (av[y])
	{
		x = 0;
		while (av[y][x])
		{
			if (!ft_isdigit(av[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putendl_fd("Erro", 2);
		exit(EXIT_FAILURE);
	}
	if (!check_args(av))
	{
		ft_putendl_fd("Erro", 2);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd("Ola mundo!\n", 1);
	return (0);
}
