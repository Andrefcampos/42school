/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:52:01 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/20 04:46:25 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	init_vars(t_vars *vars)
{
	vars->n_philo = 0;
	vars->time_die = 0;
	vars->time_eat = 0;
	vars->time_sleep = 0;
	vars->n_eat = 0;
}

int	start_mutex(pthread_mutex_t *mutex)
{
	if (!mutex)
		return (0);
	if (pthread_mutex_init(mutex, NULL))
		return (0);
	return (1);
}

static int	init_mutex(t_monitor **monitor)
{
	t_monitor			*master;

	master = *monitor;
	if (!start_mutex(&master->m_print) || !start_mutex(&master->m_time) \
		|| !start_mutex(&master->m_eat_end) || !start_mutex(&master->death))
		return (0);
	return (1);
}

int	init_monitor(t_monitor *master, char **av)
{
	master->m_forks = NULL;
	master->died = 0;
	master->start_time = 0;
	init_vars(&master->args);
	get_args(&master->args, av);
	if (!init_mutex(&master))
		return (0);
	master->start_time = get_time();
	return (1);
}
