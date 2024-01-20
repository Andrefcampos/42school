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

void	ft_process(t_pipex pipex, char **envp, char **argv)
{
	process_child(pipex.fd[],pipex.pipefd, argv, envp);
	process_child(pipex.fd[],pipex.pipefd, argv, envp);
	close(pipex.pipefd[0]);
	close(pipex.pipefd[1]);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
}

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
	ft_process(pipex, envp, argv);
	return (0);
}
