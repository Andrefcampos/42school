/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:43:27 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/20 01:51:54 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_printf("%s", ERR_INPUT);
		return (2);
	}
	if (!envp || envp[0][0] == '\0')
		ft_error(ERR_ENVP);
	if (pipe(pipex.pipefd) < 0)
	{
		ft_error(ERR_PIPEFD);
		exit(EXIT_FAILURE);
	}
	return (0);
}
