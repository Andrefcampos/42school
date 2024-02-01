/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:55:09 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/28 21:50:32 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	index_s;

	if (!big && !len)
		return (NULL);
	if (*little == '\0' || little == big)
		return ((char *)big);
	index = 0;
	while (big[index] != '\0')
	{
		index_s = 0;
		while (big[index + index_s] == little[index_s]
			&& (index + index_s) < len)
		{
			if (big[index + index_s] == '\0' && little[index_s] == '\0')
				return ((char *)&big[index]);
			index_s++;
		}
		if (little[index_s] == '\0')
			return ((char *)(big + index));
		index++;
	}
	return (NULL);
}
