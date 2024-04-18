/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:20:45 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/17 22:31:33 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft/libft.h"
#include <unistd.h>

void	put_pwd(void)
{
	char	wd[1024];
	
	getcwd(wd, sizeof(wd));
	ft_putendl_fd(wd, 1);
}

