/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:57:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/01 16:52:53 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_pipex *pipex, char *argv)
{
	int		index;
	char	*tmp;
	char	*path;

	index = 0;
	get_cmd(&pipex, argv);

}

void	process_child(t_pipex *pipex, int child)
{
	if (child == ONE)
	{
		pipex->infile = open(pipex->file1, O_RDONLY, 0644);
		{
			if (pipex->infile < 0)
				ft_error(pipex->file1, 1, strerror(errno));
		}
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		dup2(pipex->infile, STDIN_FILENO);
		close(pipex->infile);
		ft_close_pipefd(pipex->pipefd);
		exec_cmd(pipex, pipex->cmd_arg1);
	}
	else if (child == TWO)
	{
		pipex->outfile = open(pipex->file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
		{
			if (pipex->outfile < 0)
				ft_error(pipex->file2, 1, strerror(errno));
		}
		dup2(pipex->pipefd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->outfile);
		ft_close_pipefd(pipex->pipefd);
		exec_cmd(pipex, pipex->cmd_arg2);
	}
}

int	ft_process(t_pipex *pipex)
{
	int	status;

	status = 0;
	if (pipe(pipex->path) < 0)
		ft_error(ERR_PIPEFD, 130, strerror(errno));
	pipex->pid = fork();
	if (pipex->pid < 0)
		ft_error(ERR_FORK, 0, "Failed to initiate");
	else if (pipex->pid == 0)
		process_child(pipex, ONE);
	pipex->pid = fork();
	if (pipex->pid < 0)
		ft_error(ERR_FORK, 0, "Failed to initiate");
	else if (pipex->pid == 0)
		process_child(pipex, TWO);
	ft_close_pipefd(pipex->pipefd);
	waitpid(-1, &status, WUNTRACED);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (status);
}
