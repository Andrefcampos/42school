/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:20:43 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/08 17:17:24 by andrefil         ###   ########.fr       */
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

typedef struct s_data	t_data;
struct s_data
{
	t_node	*a;
	t_node	*b;
	int		max_a;
	int		max_b;
	int		min_a;
	int		min_b;
	int		moves;
};

//Check arguments passed for param:
void	validate_args(int ac, char **av);
int		check_args(char **av);
int		check_args_dup(char **av);

//Initiation:
void	init_data(t_data **data);
int		min_node(t_node **head);
int		max_node(t_node **head);

// Ordernation:
void	push_swap(int ac, char **av, t_data *data);

//Order List:
void		order_three_num(t_data *data);

//Manipulation linked list:
void	create_list(char **av, t_node **stack);
t_node	*create_node(int data);
void	list_add_next_last(t_node **head, t_node *new_node);
void	list_add_next_first(t_node **head, t_node *new_node);
void	del_one_node(t_node **head, int val);

//Swap node in list:
void	swap_first_second_node(t_node **head);
//void	swap_first_last_node(t_node **head);
void	swap_last_first_node(t_node **head);
void	swap_second_last_node(t_node **head);
void	send_in_list(t_node **stack1, t_node **stack2);
void	rotate_all_stack(t_node **head);

//Print all nodes in list:
void	print_list(t_node **list);

//Check ordenations:
int		check_orders(t_node **stack_a);

#endif
