/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:55:28 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/14 23:56:06 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	mark;
	int	index;
	int	count;

	mark = 1;
	index = 0;
	count = 0;
	while ((str[index] >= '\t' && str[index] <= '\r') || str[index] == ' ')
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			mark *= -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		count = count * 10 + (str[index] - '0');
		index++;
	}
	return (count * mark);
}
