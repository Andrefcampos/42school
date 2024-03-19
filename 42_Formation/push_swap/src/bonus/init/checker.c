/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:30:41 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/18 21:25:31 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

static int	get_moves(t_stack **stack, char *move)
{
	if (ft_strlen(move) == 3)
	{
		if (move[0] == 's' && (move[1] == 'a' || move[1] == 'b' \
			|| move[1] == 's') && move[2] == '\n')
			swap(stack, move);
		else if (move[0] == 'p' && (move[1] == 'a' || move[1] == 'b') \
				&& move[2] == '\n')
			push(stack, move);
		else if (move[0] == 'r' && (move[1] == 'a' || move[1] == 'b' \
				|| move[1] == 'r') && move[2] == '\n')
			rotate(stack, move);
	}
	else if (ft_strlen(move) == 4)
	{
		if (move[0] == 'r' && move[1] == 'r' && (move[2] == 'a' \
			|| move[2] == 'b' || move[2] == 'r') && move[3] == '\n')
			reverse_rotate(stack, move);
	}
	else
		return (0);
	return (1);
}

static void	checker(t_stack **stack)
{
	char	*move;

	while (1)
	{
		move = get_next_line(STDIN_FILENO);
		if (!move)
			break ;
		if (!get_moves(stack, move))
		{
			free(move);
			ft_putendl_fd("Error", 2);
			return ;
		}
		free(move);
	}
	if (!(*stack)->b)
	{
		if (check_sort(&(*stack)->a))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	else
		ft_putendl_fd("KO", 1);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	validate_args(ac, av);
	init_stack(&stack, av);
	checker(&stack);
	free_stack(&stack);
	return (0);
}
