/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:19:42 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/23 22:32:02 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	*ft_putstr(const char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len])
		ft_putchar(s[len++], fd);
	return (len);
}
