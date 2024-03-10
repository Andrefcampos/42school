/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:06:53 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/10 00:24:43 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	main(int ac, char **av)
{
	t_data	*data;

	validate_args(ac, av);
	init_data(&data);
	push_swap(ac, av, data);
	print_list(&data->a);
	free_data(&data);
	return (0);
}
