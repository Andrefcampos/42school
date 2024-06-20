/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:15:10 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/20 04:29:43 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	clear_philo(t_philo *philo)
{
	free(philo->last_meal);
	free(philo->life_time);
	free(philo->end_meal);
}
