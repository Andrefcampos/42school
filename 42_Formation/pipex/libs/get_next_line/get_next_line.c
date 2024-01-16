/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:35:40 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/16 18:14:24 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_make_line(t_vars *lst)
{
	t_list	*str;
	char	*line;
	int		count;

	line = (char *)malloc((lst->len + 1) * sizeof(char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	count = 0;
	str = NULL;
	while (lst->list)
	{
		str = lst->list->next;
		line[count] = lst->list->content;
		free(lst->list);
		lst->list = str;
		count++;
	}
	line[count] = '\0';
	return (line);
}

char	*ft_read_line(t_vars *lst)
{
	lst->len = 0;
	while (lst->reades_bytes > 0)
	{
		ft_lstadd_back(&lst->list, ft_lstnew(lst->buffer[lst->index]));
		if (!(lst->buffer[lst->index]) || lst->buffer[lst->index] == '\n')
			break ;
		lst->index++;
		lst->len++;
		if (lst->index >= lst->reades_bytes)
		{
			lst->index = 0;
			lst->reades_bytes = read(lst->fd, lst->buffer, BUFFER_SIZE);
			if (lst->reades_bytes == -1)
				return (ft_lstclear(&(lst->list)));
		}
	}
	lst->index++;
	lst->len++;
	return (ft_make_line(lst));
}

char	*get_next_line(int fd)
{
	static t_vars	str[1024];

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (str[fd].index >= str[fd].reades_bytes || str[fd].index == 0)
	{
		str[fd].index = 0;
		str[fd].fd = fd;
		str[fd].len = 0;
		str[fd].list = NULL;
		while (str[fd].index < BUFFER_SIZE)
			str[fd].buffer[str[fd].index++] = '\0';
		str[fd].reades_bytes = read(fd, str[fd].buffer, BUFFER_SIZE);
		if (str[fd].reades_bytes == -1)
			return (ft_lstclear(&str[fd].list));
		str[fd].index = 0;
	}
	if (str[fd].reades_bytes <= 0 || str[fd].buffer[str[fd].index] == '\0')
	{
		if (str[fd].reades_bytes < 0 && str[fd].list)
			ft_lstclear(&str[fd].list);
		return (NULL);
	}
	return (ft_read_line(&str[fd]));
}
