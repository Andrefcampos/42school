/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:50:46 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/03 21:50:19 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t num)
{
	unsigned char	*s;
	unsigned char	c;
	char			*ptr;
	int				index;

	index = 0;
	ptr = NULL;
	s = (unsigned char *)str;
	c = (unsigned char)ch;
	while (index < (int)num)
	{
		if (s[index] == c)
		{
			ptr = (void *)&s[index];
			return (ptr);
		}
		index++;
	}
	return (ptr);
}
