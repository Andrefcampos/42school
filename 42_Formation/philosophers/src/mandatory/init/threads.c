/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:49:48 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/19 05:04:41 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

static void	join_threads(pthread_t *threads, int n_philo)
{
	int	index;

	if (!threads)
		return ;
	index = -1;
	while (++index < n_philo)
		pthread_join(threads[index], NULL);
}

static void	destroy_mutex(t_monitor monitor)
{
	int	index;

	index = -1;
	while (++index < monitor.args.n_philo)
		pthread_mutex_destroy(&monitor.m_forks[index]);
	pthread_mutex_destroy(&monitor.m_print);
	pthread_mutex_destroy(&monitor.m_time);
	pthread_mutex_destroy(&monitor.dead);
}

static int	*alloc_var_time(void)
{
	int	*time;

	time = NULL;
	time = malloc(sizeof(int));
	if (!time)
		return (NULL);
	return (time);
}

void	create_new_philo(t_monitor *monitor, t_philo *philo, int index)
{
	int			position;
	
	position = index;
	philo->philo_id = index + 1;
	philo->start_time = &monitor->start_time;
	philo->args = monitor->args;
	philo->die = &monitor->die;
	philo->m_print = &(monitor->m_print);
	philo->m_time = &(monitor->m_time);
	philo->life_time = alloc_var_time();
	*(philo->life_time) = get_time() - *(philo->start_time);
	philo->last_meal = alloc_var_time();
	*(philo->last_meal) = get_time() - *(philo->start_time);
	philo->dead = &(monitor->dead);
	philo->m_forkl = &(monitor->m_forks[position]);
	if (philo->args.n_philo > 1 && position + 1 == monitor->args.n_philo)
		position = -1;
	philo->m_forkr = &(monitor->m_forks[position + 1]);
	if (philo->args.n_philo < 1)
		philo->m_forkr = NULL;
}

void	start_threads(char **av)
{
	pthread_t		*threads;
	t_monitor		monitor;
	int				index;

	threads = NULL;
	if (!init_monitor(&monitor, av))
		return ;
	threads = malloc(sizeof(pthread_t) * monitor.args.n_philo);
	if (!threads)
		return ;
	index = -1;
	while (++index < monitor.args.n_philo)
	{
		create_new_philo(&monitor, &monitor.philosophers[index], index);
		pthread_create(&threads[index], NULL, &routine, &monitor.philosophers[index]);
	}
	join_threads(threads, monitor.args.n_philo);
	destroy_mutex(monitor);
}
