/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:20:43 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/13 02:20:05 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node	t_node;
struct	s_node
{
	int		num;
	t_node	*next;
	t_node	*prev;
};

typedef struct s_var	t_var;
struct	s_var
{
	int	small_pivot;
	int	big_pivot;
	int	ra;
	int	rb;
	int	pa;
	int	pb;
};

typedef struct s_stack	t_stack;
struct	s_stack
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
};

//Check arguments passed for param:
void	validate_args(int ac, char **av);
int		check_args(char **av);
int		check_args_dup(char **av);

//Initiation:
void	init_stack(t_stack **stack, char **av);

// Sort:
void	push_swap(int ac, t_stack *stack);

//Sort List:
void	sort_three_num(t_stack *stack);
void	sort_all_num(t_stack *stack);

//Manipulation linked list:
t_node	*create_node(int stack);
t_node	*list_last(t_node **stack);
void	create_list(char **av, t_node **stack);
void	list_add_next_last(t_node **head, t_node *new_node);
void	list_add_next_first(t_node **head, t_node *new_node);
void	del_one_node(t_node **head, int val);
void	list_copy(t_node **stack, t_node **s_dest);
int		size_stack(t_node **stack);
int		min_node(t_node **head);
int		max_node(t_node **head);
int		mid_node(t_node **stack);

//Swap node in list:
void	swap_first_second_node(t_node **head);
void	send_first_to_last(t_node **head);
void	send_in_list(t_node **stack1, t_node **stack2);
void	send_last_to_first(t_node **head);

//Movements:
void	swap(t_node **stack, char *move);
void	push(t_node **stack_1, t_node **stack_2, char *move);
void	rotate(t_node **stack, char *move);
void	reverse_rotate(t_node **stack, char *move);
void	swap_double(t_node **stack_1, t_node **stack_2);
void	rotate_double(t_node **stack_1, t_node **stack_2);
void	reverse_rotate_double(t_node **stack_1, t_node **stack_2);
void	retain_last_three(t_stack *stack);

//Print all nodes in list:
void	print_list(t_node **list);

//Check sort:
int		check_sort(t_node **head);

//Free stack and list:
void	free_stack(t_stack **stack);
void	list_clear(t_node **head);

#endif
