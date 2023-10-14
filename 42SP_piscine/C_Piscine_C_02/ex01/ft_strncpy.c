/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:32:43 by andrefil          #+#    #+#             */
/*   Updated: 2023/09/02 17:07:37 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;
	int	size;

	size = n;
	i = 0;
	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
//     char dest[sizeof(argv[1])];
//     char n;

//     n = *argv[2];
//     ft_strncpy(dest, argv[1], (n - 48));

//     printf("Copied string: %s\n", dest);

//     return 0;
// }
