/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:19:33 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/19 05:04:05 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static void	set_mutex(t_philo *philo, pthread_mutex_t **first, \
						pthread_mutex_t **second)
{
	if (philo->philo_id % 2 == 0)
	{
		if (first)
			*first = philo->m_forkr;
		if (second)
			*second = philo->m_forkl;
	}
	else
	{
		if (first)
			*first = philo->m_forkl;
		if (second)
			*second = philo->m_forkr;
	}
}

void	meal(t_philo ph, int *n_eats)
{
	pthread_mutex_t		*first;
	pthread_mutex_t		*second;

	first = NULL;
	second = NULL;
	set_mutex(&ph, &first, &second);
	pthread_mutex_lock(first);
	print_log(TAKEN_FORK, ph);
	if (second)
	{
		pthread_mutex_lock(second);
		print_log(TAKEN_FORK, ph);
		print_log(EAT, ph);
		*(ph.last_meal) = current_time(ph);
		if (ph.args.n_eat)
			(*n_eats)++;
		usleep(ph.args.time_eat);
		pthread_mutex_unlock(second);
	}
	pthread_mutex_unlock(first);
}
