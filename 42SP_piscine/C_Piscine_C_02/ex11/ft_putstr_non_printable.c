/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:36:12 by andrefil          #+#    #+#             */
/*   Updated: 2023/08/30 23:52:32 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	while (str[i] <= (count + 1))
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
			str[i] = (int)str[i];
		write(1, str[i], 1);
		i++;
	}
}
