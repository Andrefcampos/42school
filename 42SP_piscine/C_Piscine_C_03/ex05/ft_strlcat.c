/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:40:13 by andrefil          #+#    #+#             */
/*   Updated: 2023/09/06 13:29:36 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_dest;
	unsigned int	size_src;
	unsigned int	i;

	size_dest = 0;
	while (dest[size_dest] != '\0')
		size_dest++;
	size_src = 0;
	while (src[size_src] != '\0')
		size_src++;
	if (size <= size_dest)
		return (size + size_src);
	i = 0;
	while (src[i] != '\0' && size_dest + 1 < size)
	{
		dest[size_dest] = src[i];
		i++;
		size_dest++;
	}
	dest[size_dest] = '\0';
	return (size_dest + size_src);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int argc, char **argv)
// {
// 	unsigned int	size_n;
// 	int	loco;
// 	int	loco1;

// 	size_n = 10;
// 	loco1 = ft_strlcat(argv[1], argv[2], size_n);
// 	// loco = strlcat(argv[1], argv[2], size_n);
// 	printf("Retorno Função que eu criei = %d\n", loco1);
// 	return (0);
// }
