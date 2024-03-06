/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:30:33 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/06 19:23:32 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <push_swap.h>
#include <libft.h>

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
			if ((av[y][0] == '-' || av[y][0] == '+') || !ft_isdigit(av[y][0]))
			{
				if (!ft_isdigit(av[y][1]))
					return (0);
			}
			if (x > 0 && !ft_isdigit(av[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_args_dup(char **av)
{
	int		y;
	int		x;

	y = 1;
	while (av[y])
	{
		if (ft_atol(av[y]) > INT_MAX || ft_atol(av[y]) < INT_MIN)
			return (0);
		x = y + 1;
		while (av[x])
		{
			if (ft_atol(av[y]) == ft_atol(av[x]))
				return (0);
			x++;
		}
		y ++;
	}
	return (1);
}
