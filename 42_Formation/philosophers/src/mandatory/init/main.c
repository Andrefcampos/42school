/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:13:14 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/20 04:47:51 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdlib.h>

void	get_args(t_vars *vars, char **av)
{
	init_vars(vars);
	if (av[1])
		vars->n_philo = ft_atol(av[1]);
	if (av[2])
		vars->time_die = ft_atol(av[2]);
	if (av[3])
		vars->time_eat = ft_atol(av[3]) * 1000;
	if (av[4])
		vars->time_sleep = ft_atol(av[4]) * 1000;
	if (av[5])
		vars->n_eat = ft_atol(av[5]);
}

int	main(int ac, char **av)
{
	t_monitor	master;

	if (!validation_args(ac, av))
		return (1);
	if (!init_monitor(&master, av))
		return (1);
	create_join_threads(&master);
	return (0);
}
