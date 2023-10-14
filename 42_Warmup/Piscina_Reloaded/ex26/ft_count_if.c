/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:55:12 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/07 13:55:55 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (tab[index])
	{
		if (f(tab[index]) == 1)
			count++;
		index++;
	}
	return (count);
}
