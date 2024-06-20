/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:49:48 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/20 04:36:40 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

static void	destroy_mutex(t_monitor *monitor)
{
	int	index;

	index = -1;
	while (++index < monitor->args.n_philo)
	{
		pthread_mutex_destroy(&monitor->m_forks[index]);
		pthread_mutex_destroy(&monitor->m_meal_philos[index]);
	}
	pthread_mutex_destroy(&monitor->m_print);
	pthread_mutex_destroy(&monitor->m_time);
	pthread_mutex_destroy(&monitor->death);
	pthread_mutex_destroy(&monitor->m_eat_end);
}

static int	*alloc_int(void)
{
	int	*time;

	time = NULL;
	time = malloc(sizeof(int));
	if (!time)
		return (NULL);
	return (time);
}

static void	create_new_philo(t_monitor *master, int index)
{
	master->philosophers[index].philo_id = index + 1;
	master->philosophers[index].args = master->args;
	master->philosophers[index].start_time = master->start_time;
	master->philosophers[index].last_meal = alloc_int();
	*(master->philosophers[index].last_meal) = get_time() - master->start_time;
	master->philosophers[index].life_time = alloc_int();
	*(master->philosophers[index].life_time) = get_time() - master->start_time;
	master->philosophers[index].died = &master->died;
	master->philosophers[index].m_forkl = &master->m_forks[index];
	if (master->args.n_philo < 2)
		master->philosophers[index].m_forkr = NULL;
	else if (index + 1 == master->args.n_philo)
		master->philosophers[index].m_forkr = &(master->m_forks[0]);
	else
		master->philosophers[index].m_forkr = &(master->m_forks[index + 1]);
	master->philosophers[index].m_print = &master->m_print;
	master->philosophers[index].death = &master->death;
	master->philosophers[index].m_time = &master->m_time;
	master->philosophers[index].m_eat_end = &master->m_eat_end;
	master->philosophers[index].m_meal = &master->m_meal_philos[index];
	master->philosophers[index].n_meal = 0;
	master->philosophers[index].end_meal = alloc_int();
	*(master->philosophers[index].end_meal) = 0;
}

static void	loop_init_mutex(pthread_mutex_t *mutex, int n_threads)
{
	int	i;

	if (!mutex)
		return ;
	i = -1;
	while (++i < n_threads)
	{
		if (pthread_mutex_init(&mutex[i], NULL))
			return ;
	}
}

void	create_join_threads(t_monitor *master)
{
	int					index;
	t_philo				philo[200];
	pthread_mutex_t		mutex_meal[200];
	pthread_mutex_t		mutex_forks[200];

	master->philosophers = philo;
	master->m_forks = mutex_forks;
	loop_init_mutex(master->m_forks, master->args.n_philo);
	master->m_meal_philos = mutex_meal;
	loop_init_mutex(master->m_meal_philos, master->args.n_philo);
	index = -1;
	while (++index < master->args.n_philo)
	{
		create_new_philo(master, index);
		pthread_create(&master->philosophers[index].philo, NULL, &routine, \
						&master->philosophers[index]);
	}
	pthread_create(&master->inspector, NULL, &watching, master);
	index = -1;
	pthread_join(master->inspector, NULL);
	while (++index < master->args.n_philo)
		pthread_join(master->philosophers[index].philo, NULL);
	destroy_mutex(master);
}
