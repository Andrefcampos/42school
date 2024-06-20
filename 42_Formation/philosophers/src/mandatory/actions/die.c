/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:10:04 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/20 04:35:18 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	die(t_philo *ph)
{
	pthread_mutex_lock(ph->m_meal);
	if (ph->args.n_eat && ph->n_meal >= ph->args.n_eat)
	{
		*(ph->end_meal) = 1;
		pthread_mutex_unlock(ph->m_meal);
		return (1);
	}
	pthread_mutex_unlock(ph->m_meal);
	pthread_mutex_lock(ph->death);
	if (current_time(ph) - *(ph->last_meal) >= ph->args.time_die \
		&& !(*ph->died))
	{
		pthread_mutex_unlock(ph->death);
		return (1);
	}
	pthread_mutex_unlock(ph->death);
	return (0);
}
