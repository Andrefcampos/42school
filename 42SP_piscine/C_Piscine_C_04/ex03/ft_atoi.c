/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:14:46 by andrefil          #+#    #+#             */
/*   Updated: 2023/09/06 18:21:40 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	index;
	int	result;
	int	sn;

	index = 0;
	sn = 1;
	while ((str[index] >= '\t' && str[index] <= '\r') || str[index] == ' ')
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sn *= -1;
		index++;
	}
	result = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = (str[index] - '0') + (result * 10);
		index++;
	}
	return (result * sn);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc > 0)
// 		printf("%d\n", ft_atoi(argv[1]));
// 	return(0);
// }
