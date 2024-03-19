/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:23:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/18 20:29:36 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void	init_stack(t_stack **stack, char **av)
{
	*stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!*stack)
		return ;
	create_list(av, &(*stack)->a);
	(*stack)->b = NULL;
}
