/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:20:45 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/21 21:08:19 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft/libft.h"
#include <unistd.h>
#include <stdio.h>

void	put_pwd(void)
{
	char	wd[1024];
	
	getcwd(wd, 1024);
	ft_putendl_fd(wd, 1);
}

static void	ch_dir(char *str)
{
	if (chdir(str) != 0)
		perror("cd");
}

void	change_dir(char *cmd)
{
	char	wd[100];

	if (!cmd)
		return ;
	getcwd(wd, 100);
	ch_dir(cmd + 3);
}
