/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:35:37 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/17 21:25:17 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_gnlvars	t_gnlvars;
struct s_gnlvars
{
	char				content;
	struct s_gnlvars	*next;
};


typedef struct s_vars	t_vars;
struct s_vars
{
	t_gnlvars	*list;
	char	buffer[BUFFER_SIZE];
	int		reades_bytes;
	int		index;
	int		len;
	int		fd;
};

char	*get_next_line(int fd);
char	*ft_read_line(t_vars *lst);
char	*ft_make_line(t_vars *lst);
void	*gnl_lstclear(t_gnlvars **lst);
void	gnl_lstadd_back(t_gnlvars **lst, t_gnlvars *new);
t_gnlvars	*gnl_lstnew(char c);

#endif
