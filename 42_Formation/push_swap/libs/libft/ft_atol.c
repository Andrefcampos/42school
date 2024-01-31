/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:27:27 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/31 17:34:22 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *nstr)
{
	int	count;
	int	signal;
	long	result;

	count = 0;
	signal = 1;
	result = 0;
	while (nstr[count] == ' ' || nstr[count] >= 9 && nstr[count] <= 13)
		count++;
	if (nstr[count] == '-' || nstr[count] == '+')
	{
		if (nstr[count] == '-')
			signal *= -1;
		count++;
	}
	while (nstr[count] >= '0' && nstr[count] <= '9')
	{
		result *= 10;
		result += nstr[count] - '0';
		count++;
	}
	return (result * signal);
}
