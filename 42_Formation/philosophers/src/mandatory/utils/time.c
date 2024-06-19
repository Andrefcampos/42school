/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:43:02 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/19 04:42:29 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time()
{
	struct timeval	ts;
	int		time_value;

	gettimeofday(&ts, NULL);
	time_value = (ts.tv_sec * 1000) + (ts.tv_usec / 1000);
	return (time_value);
}

int	get_time_thread(t_philo ph)
{
	struct timeval	ts;
	int		time_value;

	pthread_mutex_lock(ph.m_time);
	gettimeofday(&ts, NULL);
	time_value = (ts.tv_sec * 1000) + (ts.tv_usec / 1000);
	pthread_mutex_unlock(ph.m_time);
	return (time_value);
}

int	current_time(t_philo ph)
{
	int	current;

	current = get_time_thread(ph) - *(ph.start_time);
	return (current);
}
