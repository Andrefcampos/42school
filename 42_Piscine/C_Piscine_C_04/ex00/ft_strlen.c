/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:36:40 by andrefil          #+#    #+#             */
/*   Updated: 2023/09/06 19:11:22 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	printf("O tamanho dessa palavra é: %d\n", ft_strlen("safadeza"));
// 	printf("O tamanho dessa palavra é: %d\n", ft_strlen("olá"));
// 	printf("O tamanho dessa palavra é: %d\n", ft_strlen(""));
// 	printf("O tamanho dessa palavra é: %d\n", ft_strlen("hynday"));
// 	printf("O tamanho dessa palavra é: %d\n", ft_strlen("china town"));
// 	printf("O tamanho dessa palavra é: %d\n", ft_strlen("safadeza"));
// }
