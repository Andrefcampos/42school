/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:35:37 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/16 16:51:13 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_llist	t_llist;
struct s_llist
{
	char			content;
	struct s_llist	*next;
};

typedef struct s_vars	t_vars;
struct s_vars
{
	t_llist	*list;
	char	buffer[BUFFER_SIZE];
	int		reades_bytes;
	int		index;
	int		len;
	int		fd;
};

char	*get_next_line(int fd);
char	*ft_read_line(t_vars *lst);
char	*ft_make_line(t_vars *lst);
void	*ft_llstclear(t_llist **lst);
void	ft_llstadd_back(t_llist **lst, t_llist *node);
t_llist	*ft_llstnew(char c);

#endif
