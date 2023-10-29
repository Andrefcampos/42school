/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:32:29 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/28 21:50:20 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	const unsigned char	*source;
	unsigned char		*destiny;

	if (!dest && !src)
		return (dest);
	destiny = dest;
	source = src;
	while (num > 0)
	{
		*destiny++ = *source++;
		num--;
	}
	return (dest);
}
