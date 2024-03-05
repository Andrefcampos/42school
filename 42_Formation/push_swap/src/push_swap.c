/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:06:53 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/05 18:57:59 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	main(int ac, char **av)
{
	t_node	*a;
//	t_node	*b;
	int		i;

	if (ac < 2)
	{
		ft_putendl_fd("Erro", 2);
		exit(EXIT_FAILURE);
	}
	if (!check_args(av))
	{
		ft_putendl_fd("Erro", 2);
		exit(EXIT_FAILURE);
	}
	a = NULL;
	//b = NULL;
	i = 1;
	while (av[i])
		list_add_next_last(&a, create_node(ft_atol(av[i++])));
	print_list(&a);
	ft_putstr_fd("Ola mundo!\n", 1);
	return (0);
}
