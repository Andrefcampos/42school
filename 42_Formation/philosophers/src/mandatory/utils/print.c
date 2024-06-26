/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 01:03:15 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/20 01:23:23 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(const char *message, t_philo *philo)
{
	pthread_mutex_t		*print;

	print = philo->m_print;
	pthread_mutex_lock(print);
	if (!*(philo->died))
		printf(message, current_time(philo), philo->philo_id);
	pthread_mutex_unlock(print);
}
