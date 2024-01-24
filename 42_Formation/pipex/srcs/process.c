/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:57:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/24 19:30:52 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_child_one(t_pipex pipex, char *argv, char **envp)
{
	pipex.cmd_args = ft_split(argv, ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0], envp);
	printf("%s\n", pipex.cmd);
	if (pipex.cmd_args[0] != NULL && pipex.cmd)
	{
		dup2(pipex.infile, STDIN_FILENO);
		dup2(pipex.pipefd[1], STDOUT_FILENO);
		close_pipefd(pipex.pipefd);
		close(pipex.infile);
		execve(pipex.cmd, pipex.cmd_args, envp);
	}
	else
	{
		free(pipex.cmd);
		close_pipefd(pipex.pipefd);
		close(pipex.infile);
		free_matrix(pipex.cmd_args);
		ft_error(ERR_CMD, 2);
	}
}

void	process_child_two(t_pipex pipex, char *argv, char **envp)
{
	pipex.cmd_args = ft_split(argv, ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0], envp);
	printf("%s\n", pipex.cmd);
	if (pipex.cmd_args[0] != NULL && pipex.cmd)
	{
		dup2(pipex.outfile, STDOUT_FILENO);
		dup2(pipex.pipefd[0], STDIN_FILENO);
		close_pipefd(pipex.pipefd);
		close(pipex.outfile);
		execve(pipex.cmd, pipex.cmd_args, envp);
	}
	else
	{
		free(pipex.cmd);
		close_pipefd(pipex.pipefd);
		close(pipex.outfile);
		free_matrix(pipex.cmd_args);
		ft_error(ERR_CMD, 2);
	}
}

int	fork_process(t_pipex pipex, char **argv, char **envp)
{
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		return(ft_error(ERR_FORK, 2));
	else if (pipex.pid1 == 0)
	{
		pipex.infile = open(argv[1], O_RDONLY);
		if (pipex.infile < 0)
			return (ft_error(ERR_INFILE, 2));
		process_child_one(pipex, argv[2], envp);
	}
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		return (ft_error(ERR_FORK, 2));
	else if (pipex.pid2 == 0)
	{
		pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
		if (pipex.outfile < 0)
			return (ft_error(ERR_OUTFILE, 2));
		process_child_two(pipex, argv[3], envp);
	}
	close_pipefd(pipex.pipefd);
	wait_pid(&pipex);
	return (0);
}

void	close_pipefd(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
}

void	wait_pid(t_pipex *pipex)
{
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}
