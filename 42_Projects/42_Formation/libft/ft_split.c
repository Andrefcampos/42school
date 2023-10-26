/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:02:32 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/25 23:36:11 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_str(const char *s, char c)
{
	int	count_words;

	count_words = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++count_words;
		while (*s && *s != c)
			++s;
	}
	return (count_words + 1);
}

void	ft_allocate_str(char **arr, const char *s, char c)
{
	const char	*str;
	char		**arr_str;

	arr_str = arr;
	str = s;
	while (*str)
	{
		while (*s == c)
			s++;
		str = s;
		while (*str && *str != c)
			++str;
		if (*str == c || str > s)
		{
			*arr_str = ft_substr(s, 0, str - s);
			s = str;
			++arr_str;
		}
	}
	*arr_str = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**arr_str;
	int		count_str;
	int		index;

	count_str = ft_count_str(s, c);
	arr_str = (char **)mcalloc(sizeof(char *) * count_str + 1);
	if (!arr_str || !*s)
		return (NULL);
	index = 0;
	while (index < count_str)
	{


	}
	ft_allocate_str(arr_str, s, c);
	return (arr_str);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     const char *str = "Split;this,string,with,semicolon";
//     char **result = ft_split(str, ',');

//     if (result) {
//         for (int i = 0; result[i] != NULL; i++) {
//             printf("Token %d: %s\n", i, result[i]);
//             free(result[i]);
//         }
//         free(result);
//     } else {
//         printf("Erro na alocação de memória ou divisão da string.\n");
//     }

//     return 0;
// }
