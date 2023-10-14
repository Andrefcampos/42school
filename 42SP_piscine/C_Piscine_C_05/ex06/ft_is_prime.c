/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:10:03 by andrefil          #+#    #+#             */
/*   Updated: 2023/09/07 22:40:06 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	f_prime;

	f_prime = 2;
	if (nb < f_prime)
		return (0);
	while (f_prime <= nb / 2)
	{
		if (nb % f_prime == 0)
			return (0);
		f_prime++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d", ft_is_prime(13));
// 	return (0);
// }
