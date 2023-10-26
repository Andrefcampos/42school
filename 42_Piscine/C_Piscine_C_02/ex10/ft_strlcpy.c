/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 05:47:48 by andrefil          #+#    #+#             */
/*   Updated: 2023/09/02 17:28:58 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;
	int	count;
	int	size1;

	size1 = size;
	i = 0;
	count = 0;
	while ((src[i] != '\0') && (i < (size1 - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (dest[count] != '\0')
	{
		count++;
	}
	return (count);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	argc = 2;
// 	int	size;
// 	char	destination[10];

// 	size = 10;
// 	printf("Size SRC: %d\n", ft_strlcpy(destination, argv[1], size));
// 	printf("Destinantion: %s\n", destination);
// 	return (0);
// }
