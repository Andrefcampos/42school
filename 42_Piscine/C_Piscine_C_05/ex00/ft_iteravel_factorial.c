/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iteravel_factorial.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:15:12 by andrefil          #+#    #+#             */
/*   Updated: 2023/09/07 18:03:57 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iteral_factorial(int nb)
{
	int	i;

	i = nb;
	while (i > 1)
	{
		nb *= (i - 1);
		i--;
	}
	return (nb);
}

// #include <stdio.h>

// int	main()
// {
// 	printf("%d", ft_iteral_factorial(5));
// 	return (0);
// }
