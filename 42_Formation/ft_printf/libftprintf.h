/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 04:05:04 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/23 22:32:26 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_list	t_list;
struct s_list
{
	char	*content;
	s_list	*next;
};

int	ft_putchar(int c, int fd);
int	*ftputstr(const char *s, int fd);

#endif
