/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:55:28 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/26 04:59:12 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	mark;
	size_t	index;
	size_t	count;

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
