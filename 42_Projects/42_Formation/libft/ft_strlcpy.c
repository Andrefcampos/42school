/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:24:39 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/26 03:26:05 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, int size)
{
	size_t	index;

	if (size != 0)
	{
		index = 0;
		while (src[index] != '\0' && index < (size -1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (ft_strlen(src));
}
