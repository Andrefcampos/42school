/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:52:32 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/17 14:10:41 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	list_iter(t_node **lst, char *s, \
		void (*f)(t_node **, char *), int size)
{
	while (size--)
		(*f)(lst, s);
}

void	stacks_iter(t_node **lst1, t_node **lst2, \
		void (*f)(t_node **, t_node **), int size)
{
	while (size--)
		(*f)(lst1, lst2);
}

void	stack_iter(t_stack **stack, char *move, \
		void (*f)(t_stack **, char *), int size)
{
	while (size--)
		(*f)(stack, move);
}
