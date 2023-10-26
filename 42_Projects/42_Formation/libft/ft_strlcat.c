/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 02:25:46 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/26 00:53:08 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, int size)
{
	char	*ptr;
	int		count_dest;
	int		count_src;

	ptr = (char *)src;
	count_dest = 0;
	count_src = 0;
	while (count_dest < size && *dest)
	{
		dest++;
		count_dest++;
	}
	if (count_dest == size)
		return (count_dest + ft_strlen(src));
	while (ptr[count_src])
	{
		if (count_src < (size - count_dest) - 1)
			*dest++ = ptr[count_src];
		count_src++;
	}
	*dest = '\0';
	return (count_dest + count_src);
}
