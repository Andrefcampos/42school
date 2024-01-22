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

void	process_child(char **argv, char**envp)
{

}

void	dp_cl_process(int fd, int *pipefd, int child)
{
	if (child == 1)
	{
		dup2(fd, STDIN_FILENO);
		dup2(pipefd[child], STDOUT_FILENO);
	}
	if (child == 0)
	{
		dup2(fd, STOUT_FILENO);
		dup2(pipefd[child], STDIN_FILENO);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return(ft_error(ERR_INPUT, 2));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipe.infile < 0)
		ft_error(ERR_INFILE);

	if (pipe(pipex.pipefd) < 0)
	{
		ft_error(ERR_PIPEFD);
		exit(EXIT_FAILURE);
	}
	ft_process(pipex, envp, argv);
	return (0);
}
