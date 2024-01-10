/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:58:13 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/05 12:59:14 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	index;

	result = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!result)
		return (NULL);
	index = 0;
	while (index < ft_strlen(s))
	{
		result[index] = f(index, s[index]);
		index++;
	}
	return (result);
}
