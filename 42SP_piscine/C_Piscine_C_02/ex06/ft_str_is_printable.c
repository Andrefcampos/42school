/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 02:52:53 by andrefil          #+#    #+#             */
/*   Updated: 2023/08/31 03:29:25 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
//     if (argc < 2)
//     {
//         printf("Insufficient arguments. \n");
//         return (1);
//     }
//     // char    car;

//     // car = '\n';

//     // printf("%d\n", ft_str_is_printable(&car));
//     printf("%d\n", ft_str_is_printable(argv[1]));
//     return (0);
// }
