/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:20:45 by andrefil          #+#    #+#             */
/*   Updated: 2024/05/02 01:01:30 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	put_pwd(char *input)
{
	char	wd[1024];

	if (ft_strncmp(input, "pwd", 4))
		return (0);
	getcwd(wd, 1024);
	ft_putendl_fd(wd, 1);
	return (1);
}

static void	ch_dir(char *input)
{
	if (chdir(input) != 0)
		perror("cd");
}

int	change_dir(char *input)
{
	char	wd[100];

	if (ft_strncmp(input, "cd", 2))
		return (0);
	getcwd(wd, 100);
	ch_dir(input + 3);
	return (1);
}

int	ft_clear(char *input)
{
	if (ft_strncmp(input, "clear", 6) == 0)
	{
		ft_putendl_fd("\e[2J\e[H", 1);
		return (1);
	}
	return (0);
}

int	call_builtins(char *input)
{
	if (ft_clear(input))
		return (1);
	else if (put_pwd(input))
		return (1);
	else if (change_dir(input))
		return (1);
	return (0);
}
