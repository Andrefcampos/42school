/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_strcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:59:38 by andrefil          #+#    #+#             */
/*   Updated: 2023/09/04 21:56:41 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int	main(int argc, char **argv)
// {
// 	char	*dest;
// 	char	*source;

// 	dest = argv[1];
// 	source = argv[2];
// 	printf("%s\n", ft_strcat(dest, source));
// 	return (0);
// }
