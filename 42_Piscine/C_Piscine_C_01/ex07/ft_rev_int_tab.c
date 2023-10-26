/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 01:16:15 by andrefil          #+#    #+#             */
/*   Updated: 2023/08/29 16:14:49 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_rev_int_tab(int	*tab, int size)
{
	int	index;
	int	final;

	index = 0;
	final = size - 1;
	while (index < size / 2)
	{
		ft_swap(&tab[index], &tab[final - index]);
		index++;
	}
}
// #include <stdio.h>
// int	main(void)
// {
// 	int	size = 6;
// 	int	arr[] = {1, 2, 66, 6, 3, 0};
// 	int	i;
// 	printf("Original: \n");
// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		printf("%d-", arr[i]);
// 		i++;
// 	}
// 	printf("%d", arr[size - 1]);
// 	printf("\n");
// 	ft_rev_int_tab(arr, size);
// 	printf("\n");
// 	printf("Mudança: \n");
// 	i = 0;
// 	while (i < size -1)
// 	{
// 		printf("%d-", arr[i]);
// 		i++;
// 	}
// 	printf("%d", arr[size - 1]);
// 	return (0);
// }
