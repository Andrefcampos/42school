/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:19:33 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/20 00:40:18 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static void	set_mutex(t_philo *philo, pthread_mutex_t **first, \
						pthread_mutex_t **second)
{
	if (philo->philo_id % 2 == 0)
	{
		if (philo->m_forkr)
			*first = philo->m_forkr;
		if (philo->m_forkl)
			*second = philo->m_forkl;
	}
	else
	{
		if (philo->m_forkl)
			*first = philo->m_forkl;
		if (philo->m_forkr)
			*second = philo->m_forkr;
	}
}

void	meal(t_philo *ph)
{
	pthread_mutex_t		*first;
	pthread_mutex_t		*second;

	first = NULL;
	second = NULL;
	set_mutex(ph, &first, &second);
	pthread_mutex_lock(first);
	print_log(TAKEN_FORK, ph);
	if (second)
	{
		pthread_mutex_lock(second);
		print_log(TAKEN_FORK, ph);
		print_log(EAT, ph);
		pthread_mutex_lock(ph->m_meal);
		*(ph->last_meal) = current_time(ph);
		if (ph->args.n_eat)
			ph->n_meal++;
		pthread_mutex_unlock(ph->m_meal);
		usleep(ph->args.time_eat);
		pthread_mutex_unlock(second);
	}
	pthread_mutex_unlock(first);
}
