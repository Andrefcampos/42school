/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:43:27 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/24 11:48:43 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_error(ERR_INPUT, 2));
	if (pipe(pipex.pipefd) < 0)
	{
		ft_error(ERR_PIPEFD, 2);
		exit(EXIT_FAILURE);
	}
	return (fork_process(pipex, argv, envp));
}
