/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:24:25 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/28 21:49:59 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	if (!dest && !src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, num));
	while (num--)
		((unsigned char *)dest)[num] = ((unsigned char *)src)[num];
	return (dest);
}
