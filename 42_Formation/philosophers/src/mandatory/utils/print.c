/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 01:03:15 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/19 05:35:17 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(const char *message, t_philo philo)
{
	pthread_mutex_t		*print;

	print = philo.m_print;
	pthread_mutex_lock(print);
	die(philo);
	if (!*(philo.die))
		printf(message, current_time(philo), philo.philo_id);
	*(philo.life_time) = current_time(philo) - *(philo.last_meal);
	pthread_mutex_unlock(print);
}
