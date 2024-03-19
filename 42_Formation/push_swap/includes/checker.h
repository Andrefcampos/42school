/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:31:31 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/19 11:46:09 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef struct s_node	t_node;
struct	s_node
{
	int		num;
	t_node	*next;
	t_node	*prev;
};

typedef struct s_stack	t_stack;
struct	s_stack
{
	t_node	*a;
	t_node	*b;
};

// Validate functions:
void	validate_args(int ac, char **av);
int		check_args(char **av);
int		check_args_dup(char **av);
int		check_sort(t_node **head);

// Movements:
void	swap(t_stack **stack, char *move);
void	push(t_stack **stack, char *move);
void	push(t_stack **stack, char *move);
void	rotate(t_stack **stack, char *move);
void	reverse_rotate(t_stack **stack, char *move);

// Utils functions:
t_node	*list_last(t_node **stack);
t_node	*create_node(int stack);
void	create_list(char **av, t_node **stack);
void	list_add_next_last(t_node **head, t_node *new_node);
void	list_add_next_first(t_node **head, t_node *new_node);
void	swap_first_second_node(t_node **head);
void	send_last_to_first(t_node **head);
void	send_first_to_last(t_node **head);
void	send_in_list(t_node **stack1, t_node **stack2);
int		size_list(t_node **head);

// Clear and free:
void	free_stack(t_stack **stack);
void	list_clear(t_node **head);

#endif
