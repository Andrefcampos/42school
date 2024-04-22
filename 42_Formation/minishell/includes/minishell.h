/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:00:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/21 20:18:13 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_node	t_node;
struct	s_node
{
	void	*content;
	t_node	*prev;
	t_node	*next;
};

typedef struct s_llist	t_llist;
struct	s_llist
{
	t_node	*list;
	t_llist	*prev;
	t_llist	*next;
};

typedef struct s_data	t_data;
struct s_data
{
	t_llist	*cmd;
	int		index;
};

//Manipulate list:
t_node	*create_node(char *str);
void	add_last_node(t_node **head, t_node *node);
t_node	*last_node(t_node	**head);
void	put_pwd(void);
void	change_dir(char *cmd);

#endif
