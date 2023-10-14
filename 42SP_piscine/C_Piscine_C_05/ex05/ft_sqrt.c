/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:42:30 by andrefil          #+#    #+#             */
/*   Updated: 2023/09/07 20:01:01 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	square;

	square = 1;
	while (square < nb)
	{
		if (square * square == nb)
			return (square);
		square++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf ("%d", ft_sqrt(3437316));
// 	return (0);
// }
