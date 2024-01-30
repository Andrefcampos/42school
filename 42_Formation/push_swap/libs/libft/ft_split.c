/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:02:32 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/03 14:23:11 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_str(const char *s, char c)
{
	int	count_words;

	if (!s)
		return (0);
	count_words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count_words++;
		while (*s && *s != c)
			s++;
	}
	return (count_words);
}

static void	ft_allocate_str(char **arr, const char *s, char c)
{
	size_t	len_str;
	int		index;
	int		pos_arr;

	len_str = 0;
	index = 0;
	pos_arr = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c && *s)
			index++;
		if (s[index] != '\0')
		{
			len_str = 0;
			while ((s[index + len_str] != c) && (s[index + len_str] != '\0'))
				len_str++;
			arr[pos_arr++] = ft_substr(s, index, len_str);
			index += len_str;
		}
	}
	arr[pos_arr] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**arr_str;

	arr_str = (char **)malloc(sizeof(char *) * (ft_count_str(s, c) + 1));
	if (!arr_str || !s)
		return (NULL);
	ft_allocate_str(arr_str, s, c);
	return (arr_str);
}
