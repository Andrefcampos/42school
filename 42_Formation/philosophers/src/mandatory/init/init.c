/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:52:01 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/19 04:18:27 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	init_vars(t_vars *vars)
{
	vars->n_philo = 0;
	vars->time_die = 0;
	vars->time_eat = 0;
	vars->time_sleep = 0;
	vars->n_eat = 0;
}

int	init_monitor(t_monitor *monitor, char **av)
{
	int	i;

	monitor->philosophers = NULL;
	monitor->m_forks = NULL;
	monitor->die = 0;
	monitor->start_time = 0;
	init_vars(&monitor->args);
	get_args(&monitor->args, av);
	pthread_mutex_init(&monitor->m_print, NULL);
	pthread_mutex_init(&monitor->m_time, NULL);
	pthread_mutex_init(&monitor->dead, NULL);
	monitor->philosophers = malloc(sizeof(t_philo) * monitor->args.n_philo);
	if (!monitor->philosophers)
		return (0);
	monitor->m_forks = malloc(sizeof(pthread_mutex_t) * monitor->args.n_philo);
	if (!monitor->m_forks)
		return (0);
	i = -1;
	while (++i < monitor->args.n_philo)
		pthread_mutex_init(&monitor->m_forks[i], NULL);
	monitor->start_time = get_time();
	return (1);
}

