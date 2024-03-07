/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:06:53 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/06 21:59:39 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	main(int ac, char **av)
{
	t_node	*a;
	//t_node	*b;
	int		i;

	if (ac == 2)
	{
		ft_putendl_fd("Erro", 2);
		exit(EXIT_FAILURE);
	}
	if (!check_args(av) || !check_args_dup(av))
	{
		ft_putendl_fd("Erro", 2);
		exit(EXIT_FAILURE);
	}
	a = NULL;
//	b = NULL;
	i = 1;
	while (av[i])
		list_add_next_last(&a, create_node(ft_atol(av[i++])));
/*
	while (a)
		send_in_list(&a, &b);
 */
	if (a)
		print_list(&a);
	order_three_num(&a);
	ft_putendl_fd("ordenacao:", 1);
	if (a)
		print_list(&a);
//	print_list(&b);
	return (0);
}
