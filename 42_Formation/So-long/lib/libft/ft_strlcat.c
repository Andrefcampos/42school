/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 02:25:46 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/28 21:47:31 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count_dest;
	size_t	count_src;
	size_t	len_src;
	size_t	len_dest;

	len_src = ft_strlen(src);
	if (!dest && size == 0)
		return (len_src);
	count_dest = ft_strlen(dest);
	len_dest = count_dest;
	if (size <= count_dest)
		return (size + len_src);
	count_src = 0;
	while (src[count_src] && count_dest + 1 < size)
	{
		dest[count_dest] = src[count_src];
		count_src++;
		count_dest++;
	}
	dest[count_dest] = '\0';
	return (len_dest + len_src);
}
