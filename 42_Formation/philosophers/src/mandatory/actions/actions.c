/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:11:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/20 05:35:35 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static int	life_is_over(t_philo *philo)
{
	int		death;

	death = *(philo->died);
	pthread_mutex_lock(philo->death);
	if (death)
	{
		pthread_mutex_unlock(philo->death);
		return (1);
	}
	pthread_mutex_unlock(philo->death);
	pthread_mutex_lock(philo->m_meal);
	if (philo->args.n_eat && philo->n_meal >= philo->args.n_eat)
	{
		pthread_mutex_unlock(philo->m_meal);
		return (1);
	}
	pthread_mutex_unlock(philo->m_meal);
	return (0);
}

static int	inspec_philos(t_monitor **master, int philo, int *i)
{
	t_monitor	*monitor;

	monitor = *master;
	pthread_mutex_lock(&monitor->m_meal_philos[philo]);
	pthread_mutex_lock(&monitor->death);
	if (current_time(&monitor->philosophers[philo]) - \
		*(monitor->philosophers[philo].last_meal) >= monitor->args.time_die)
	{
		if (!*(monitor->philosophers[philo].end_meal))
		{
			pthread_mutex_lock(&monitor->m_print);
			monitor->died++;
			printf(DIE, current_time(&monitor->philosophers[philo]), \
					monitor->philosophers[philo].philo_id);
			pthread_mutex_unlock(&monitor->m_print);
		}
		if (*(monitor->philosophers[philo].end_meal) == 1)
			(*i)++;
		pthread_mutex_unlock(&monitor->death);
		pthread_mutex_unlock(&monitor->m_meal_philos[philo]);
		return (0);
	}
	pthread_mutex_unlock(&monitor->death);
	pthread_mutex_unlock(&monitor->m_meal_philos[philo]);
	return (1);
}

void	*watching(void *master)
{
	t_monitor	*monitor;
	int			philo;
	int			philos_eat;

	monitor = (t_monitor *) master;
	philo = 0;
	philos_eat = 0;
	while (!monitor->died && philos_eat < monitor->args.n_philo)
	{
		philo = -1;
		while (++philo < monitor->args.n_philo)
		{
			if (!inspec_philos(&monitor, philo, &philos_eat))
				break ;
		}
		if (monitor->died || philos_eat >= monitor->args.n_philo)
			break ;
		usleep(1000);
	}
	return ((void *)0);
}

void	*routine(void *philo)
{
	t_philo			ph;

	ph = *(t_philo *)philo;
	while (!life_is_over(&ph))
	{
		meal(&ph);
		if (die(&ph))
			break ;
		sleeping(&ph);
		if (die(&ph))
			break ;
		thinking(&ph);
		if (die(&ph))
			break ;
	}
	usleep(1000);
	clear_philo(&ph);
	return ((void *)0);
}
