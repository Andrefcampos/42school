/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:10:04 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/19 05:59:45 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	die(t_philo ph)
{
	if (*(ph.life_time) > ph.args.time_die && !(*ph.die))
	{
		pthread_mutex_lock(ph.m_print);
		(*(ph.die))++;
		printf(DIE, current_time(ph), ph.philo_id);
		pthread_mutex_unlock(ph.m_print);
	}
}
