/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:51:45 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/05 16:50:59 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb;
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb <= 1)
		return (1);
	while (i > 1)
		nb *= --i;
	return (nb);
}
