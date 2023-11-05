/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:09:58 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/05 13:00:38 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t num)
{
	char	*string;
	size_t	index;

	string = (char *)str;
	index = 0;
	while (index < num)
		string[index++] = ch;
	return (str);
}
