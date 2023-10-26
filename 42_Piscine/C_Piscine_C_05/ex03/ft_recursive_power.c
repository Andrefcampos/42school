/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:12:28 by andrefil          #+#    #+#             */
/*   Updated: 2023/09/07 20:09:31 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	if (result > result * nb)
		return (0);
	else if (power > 1)
		return (result * ft_recursive_power(result, power - 1));
	else if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d", ft_recursive_power(0, 0));
// 	return (0);
// }
