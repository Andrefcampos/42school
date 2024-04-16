/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:00:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/16 16:11:15 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEL_H
# define MINISHEL_H

typedef struct s_node	t_node;
struct	s_node
{
	void	*content;
	t_node	*prev;
	t_node	*next;
};

typedef struct s_list	t_list;
struct	s_list
{
	t_node	*node;
	t_list	*prev;
	t_list	*next;
};

typedef struct s_data	t_data;
struct s_data
{
	t_list	*cmd;
	int		index;
};


#endif
