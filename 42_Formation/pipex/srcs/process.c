/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:57:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/03 22:24:07 by andrefil         ###   ########.fr       */
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
		temp = ft_strjoin(pipex->path[index], "/");
		path = ft_strjoin(temp, pipex->cmd->bin);
		free(temp);
		if (path && access(path, F_OK | X_OK) == 0 \
			&& execve(path, pipex->cmd->flag, envp) < 0)
		{
			free (path);
			ft_error(pipex, pipex->cmd->bin, strerror(errno), 127);
		}
		index++;
		free(path);
	}
	if (pipex->cmd->bin && access(pipex->cmd->bin, F_OK) == 0)
		if (execve(pipex->cmd->bin, pipex->cmd->flag, envp) < 0)
			ft_error(pipex, pipex->cmd->bin, strerror(errno), 126);
	if (pipex->cmd->bin && pipex->cmd->bin[0] == '/')
		ft_error(pipex, pipex->cmd->bin, "No such file or directory", 0);
	ft_error(pipex, pipex->cmd->bin, "command not found", 127);
}

static void	open_fd(t_pipex *pipex, int child)
{
	if (child == ONE)
	{
		pipex->infile = open(pipex->file1, O_RDONLY, 0644);
		{
			if (pipex->infile < 0)
				ft_error(pipex, pipex->file1, strerror(errno), 1);
		}
	}
	else if (child == TWO)
	{
		pipex->outfile = open(pipex->file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
		{
			if (pipex->outfile < 0)
				ft_error(pipex, pipex->file2, strerror(errno), 1);
		}
	}
}

void	process_child(t_pipex *pipex, char **argv, int child, char **envp)
{
	if (child == ONE)
	{
		open_fd(pipex, child);
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		dup2(pipex->infile, STDIN_FILENO);
		close(pipex->infile);
	}
	else if (child == TWO)
	{
		open_fd(pipex, child);
		dup2(pipex->pipefd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->outfile);
	}
	ft_close_pipefd(pipex->pipefd);
	exec_cmd(pipex, argv[child + 1], envp);
}

int	ft_process(t_pipex *pipex, char **argv, char **envp)
{
	pipex->status = 0;
	pipex->process = 1;
	if (pipe(pipex->pipefd) < 0)
		ft_error(pipex, ERR_PIPEFD, strerror(errno), 130);
	while (pipex->process <= 2)
	{
		pipex->pid = fork();
		if (pipex->pid < 0)
			ft_error(pipex, ERR_FORK, "Failed to initiate", 0);
		else if (pipex->pid == 0)
			process_child(pipex, argv, pipex->process, envp);
		pipex->process++;
	}
	ft_close_pipefd(pipex->pipefd);
	waitpid(pipex->pid, &pipex->status, 0);
	free_pipex(pipex);
	free(pipex->file1);
	free(pipex->file2);
	if (WIFEXITED(pipex->status))
		return (WEXITSTATUS(pipex->status));
	return (pipex->status);
}
