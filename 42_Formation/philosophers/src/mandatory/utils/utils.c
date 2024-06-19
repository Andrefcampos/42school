/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:20:37 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/19 01:07:06 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long	ft_atol(const char *num)
{
	int		signal;
	size_t	index;
	long	n;

	if (!num)
		return (0);
	signal = 1;
	index = 0;
	n = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		if (num[0] == '-')
			signal *= -1;
		index++;
	}
	while (num[index] > 47 && num[index] < 58)
	{
		n *= 10;
		n += num[index++] - 48;
	}
	return (n * signal);
}
