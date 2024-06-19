/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:11:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/19 05:59:16 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int life_is_over(t_philo *philo, int n_eats);

void	*routine(void *philo)
{
	t_philo			ph;
	int				n_eats;

	ph = *(t_philo *)philo;
	n_eats = 0;
	if (!ph.args.n_eat)
		n_eats = -1;
	while (!life_is_over(&ph, n_eats))
	{
		meal(ph, &n_eats);
		sleeping(ph);
		thinking(ph);
	}
	return ((void *)0);
}

int life_is_over(t_philo *philo, int n_eats)
{
	pthread_mutex_lock(philo->dead);
	if (*(philo->die))
	{
		pthread_mutex_unlock(philo->dead);
		return (1);
	}
	pthread_mutex_unlock(philo->dead);
	return (0);
}
