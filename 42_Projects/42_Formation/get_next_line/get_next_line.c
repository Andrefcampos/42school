/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:13:17 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/20 17:50:22 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_make_line(t_vars *lst)
{
	t_list	*str;
	char	*line;
	int		count;

	line = malloc((lst->len + 1) * sizeof(char));
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
	while (lst->read_bytes > 0)
	{
		ft_lstadd_back(&lst->list, ft_lstnew(lst->buffer[lst->index]));
		if (!(lst->buffer[lst->index]) || lst->buffer[lst->index] == '\n')
			break ;
		lst->index++;
		lst->len++;
		if (lst->index >= lst->read_bytes)
		{
			lst->index = 0;
			lst->read_bytes = read(lst->fd, lst->buffer, BUFFER_SIZE);
			if (lst->read_bytes == -1)
				return (ft_lstclear(&(lst->list)));
		}
	}
	lst->index++;
	lst->len++;
	return (ft_make_line(lst));
}

char	*get_next_line(int fd)
{
	static t_vars	str;

	if (fd < 0)
		return (NULL);
	if (str.index >= str.read_bytes || str.index == 0)
	{
		str.index = 0;
		str.fd = fd;
		str.len = 0;
		str.list = NULL;
		while (str.index < BUFFER_SIZE)
			str.buffer[str.index++] = '\0';
		str.read_bytes = read(fd, str.buffer, BUFFER_SIZE);
		if (str.read_bytes == -1)
			return (ft_lstclear(&str.list));
		str.index = 0;
	}
	if (str.read_bytes <= 0 || str.buffer[str.index] == '\0')
	{
		if (str.read_bytes < 0 && str.list)
			ft_lstclear(&str.list);
		return (NULL);
	}
	return (ft_read_line(&str));
}
