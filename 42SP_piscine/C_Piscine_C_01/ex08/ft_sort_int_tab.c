/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:29:47 by andrefil          #+#    #+#             */
/*   Updated: 2023/08/29 16:22:36 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j + 1], &tab[j]);
			j++;
		}
		i++;
	}
}

// #include <stdio.h>

// int main(void)
// {
//     int arr[] = {5, 9, 1, 25, 0, 9, 8};
//     int i;
//     int size;
//     size = 7;
//     ft_sort_int_tab(arr, size);
//     i = 0;
//     while(i < size)
//     {
//         printf("%d-", arr[i]);
//         i++;
//     }
//     return (0);
// }
