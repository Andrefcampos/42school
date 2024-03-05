/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:20:43 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/05 18:57:47 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node t_node;
struct s_node
{
  int		num;
  t_node	*next;
  t_node	*prev;
};

int		check_args(char **av);
t_node	*create_node(int data);
void	list_add_next_last(t_node **head, t_node *new_node);
void	list_add_next_front(t_node **head, t_node *new_node);
void	del_one_node(t_node **head, int val);
void	swap_first_second_node(t_node **head);
//void	swap_first_last_node(t_node **head);
void	swap_last_first_node(t_node **head);
void	print_list(t_node **list);

#endif
