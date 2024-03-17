/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:06:53 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/17 13:19:49 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	main(int ac, char **av)
{
	t_stack	*stack;

	validate_args(ac, av);
	init_stack(&stack, av);
	push_swap(ac, &stack);
	print_list(&stack->a);
	free_stack(&stack);
	return (0);
}
