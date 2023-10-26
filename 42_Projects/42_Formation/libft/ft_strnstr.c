/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:55:09 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/25 18:34:42 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	int	num;

	if (*little == 0)
		return ((char *)big);
	num = ft_strlen(little);
	if (len == 0)
		return (0);
	while (*big && num <= len)
	{
		if (*big == *little && ft_strncmp(big, little, num) == 0)
			return ((char *)big);
		++big;
		--len;
	}
	return (NULL);
}
