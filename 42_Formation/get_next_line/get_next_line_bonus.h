/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:35:37 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/20 20:31:18 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list	t_list;
struct s_list
{
	char			content;
	struct s_list	*next;
};

typedef struct s_vars	t_vars;
struct s_vars
{
	t_list	*list;
	char	buffer[BUFFER_SIZE];
	int		reades_bytes;
	int		index;
	int		len;
	int		fd;
};

char	*get_next_line(int fd);
char	*ft_read_line(t_vars *lst);
char	*ft_make_line(t_vars *lst);
void	*ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char c);

#endif
