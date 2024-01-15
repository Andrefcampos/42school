/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:24:52 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/28 21:50:39 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	index_s;
	size_t	index;

	index_s = start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) >= ft_strlen(s))
		len = ft_strlen(s) - start;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	index = 0;
	while (index_s < ft_strlen(s) && index < len)
		sub_str[index++] = s[index_s++];
	sub_str[index] = '\0';
	return (sub_str);
}
