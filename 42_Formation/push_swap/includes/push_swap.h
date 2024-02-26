/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:20:43 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/26 15:49:45 by andrefil         ###   ########.fr       */
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
	int			num;
	t_node		*top;
	t_node		*bot;
};

typedef struct s_node	t_node;
struct	s_node
{
	int			val;
	t_node		*next;
	t_node		*prev;
};

#endif
