/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:03:51 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/05 22:12:53 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	result;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	result = max - min;
	arr = malloc(sizeof(int) * result);
	while (i < result)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
