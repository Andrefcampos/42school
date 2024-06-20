/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:09:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/20 05:58:02 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_av(char *arg)
{
	int	index;

	if (!arg)
		return (0);
	index = 0;
	while (arg[index])
	{
		if (arg[index] < 48 || arg[index++] > 57)
		{
			printf("Input error. Put only numbers.");
			return (0);
		}
	}
	return (1);
}

int	validation_args(int ac, char **av)
{
	int	index;

	index = 1;
	if (ac < 5 || ac > 7)
	{
		printf("Input error: [number_of_philosophers], [time_to_die], \
		[time_to_eat], [time_to_sleep], \
		[number_of_times_each_philosopher_must_eat]");
		return (0);
	}
	while (av[index])
	{
		if (ft_atol(av[1]) > 200 || ft_atol(av[1]) < 0)
		{
			printf("Number of philosophers incorrect. Valid: 1 - 200.");
			return (0);
		}
		if (!check_av(av[index++]))
			return (0);
		else if ((index > 1 && index < 5) && ft_atol(av[index]) < 60)
		{
			printf("Input error. Valid: > 60ms.");
			return (0);
		}
	}
	return (1);
}
