/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:33:49 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/07 22:11:03 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int	ft_display_file(char *file)
{
	char	buff[1024 + 1];
	int		size;
	int		desc_file;

	desc_file = open(file, O_RDONLY);
	if (desc_file == -1)
	{
		ft_putstr("Cannot read file.\n");
		close(desc_file);
		return (1);
	}
	while (desc_file)
	{
		size = read(desc_file, buff, 1024);
		if (size == 0)
			break ;
		if (size == -1)
			ft_putstr("Cannot read file.\n");
		buff[size] = 0;
		ft_putstr(buff);
	}
	close(desc_file);
	return (0);
}
