/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:20:43 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/31 16:20:25 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack	t_stack;
struct	s_stack
{
	int			n;
	int			cost_a;
	int			cost_b;
	int			cost_move;
	t_stack		*target;
	t_stack		*next;
	t_stack		*prev;
};

#endif
