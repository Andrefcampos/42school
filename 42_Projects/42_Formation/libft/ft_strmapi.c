/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:58:13 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/03 21:51:15 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		index;

	result = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!result)
		return (NULL);
	index = 0;
	while (index < (int)ft_strlen(s))
	{
		result[index] = f(index, s[index]);
		index++;
	}
	return (result);
}
