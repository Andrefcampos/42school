/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:57:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/05 13:51:35 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_pipex *pipex, char *argv, char **envp)
{
	int		index;
	char	*temp;
	char	*path;

	index = 0;
	get_cmd(&pipex, argv);
	while (pipex->path && pipex->path[index])
	{
		temp = ft_strjoin(pipex->path[index++], "/");
		path = ft_strjoin(temp, pipex->cmd->bin);
		free(temp);
		if (path && access(path, F_OK | X_OK) == 0 \
		&& execve(path, pipex->cmd->flag, envp) < 0)
		{
			free (path);
			ft_error(pipex, pipex->cmd->bin, strerror(errno), 127);
		}
		free(path);
	}
	if (pipex->cmd->bin && access(pipex->cmd->bin, F_OK) == 0)
		if (execve(pipex->cmd->bin, pipex->cmd->flag, envp) < 0)
			ft_error(pipex, pipex->cmd->bin, strerror(errno), 126);
	if (pipex->cmd->bin && pipex->cmd->bin[0] == '/')
		ft_error(pipex, pipex->cmd->bin, "No such file or directory", 0);
	ft_error(pipex, pipex->cmd->bin, "command not found", 127);
}

static void	open_fd(t_pipex *pipex, int child, char **argv)
{
	if (child == ONE)
	{
		pipex->infile = open(argv[1], O_RDONLY, 0644);
		{
			if (pipex->infile < 0)
				ft_error(pipex, argv[1], strerror(errno), 1);
		}
	}
	else if (child == TWO)
	{
		pipex->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		{
			if (pipex->outfile < 0)
				ft_error(pipex, argv[4], strerror(errno), 1);
		}
	}
}

void	process_child(t_pipex *pipex, char **argv, int child, char **envp)
{
	if (child == ONE)
	{
		open_fd(pipex, child, argv);
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		dup2(pipex->infile, STDIN_FILENO);
		close(pipex->infile);
	}
	else if (child == TWO)
	{
		open_fd(pipex, child, argv);
		dup2(pipex->pipefd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->outfile);
	}
	ft_close_pipefd(pipex->pipefd);
	exec_cmd(pipex, argv[child + 1], envp);
}

int	ft_process(t_pipex *pipex, char **argv, char **envp)
{
	if (pipe(pipex->pipefd) < 0)
		ft_error(pipex, ERR_PIPEFD, strerror(errno), 130);
	pipex->process = ONE;
	while (pipex->process <= TWO)
	{
		pipex->pid = fork();
		if (pipex->pid < 0)
			ft_error(pipex, ERR_FORK, "Failed to initiate", 0);
		else if (pipex->pid == 0)
			process_child(pipex, argv, pipex->process, envp);
		pipex->process++;
	}
	ft_close_pipefd(pipex->pipefd);
	pipex->status = 0;
	waitpid(pipex->pid, &pipex->status, 0);
	free_pipex(pipex);
	if (WIFEXITED(pipex->status))
		return (WEXITSTATUS(pipex->status));
	return (pipex->status);
}
