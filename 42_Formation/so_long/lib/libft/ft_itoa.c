/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:07:24 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/27 15:42:06 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(long int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*str_num;
	int			size;

	num = n;
	if (num < 0)
	{
		num *= -1;
		size = ft_get_size(num) + 1;
	}
	else
		size = ft_get_size(num);
	str_num = ft_calloc((size + 1), sizeof(char));
	if (!str_num)
		return (NULL);
	while (size-- > 0)
	{
		str_num[size] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str_num[0] = '-';
	return (str_num);
}
