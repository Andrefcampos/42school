/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:57:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/30 16:00:51 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	process_child_one(t_pipex pipex, char **argv, char **envp)
{
	char	**cmd;
	char	*cmd_path;

	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_error(argv[1], 1, strerror(errno));
	cmd = ft_split(argv[2], ' ');
	cmd_path = get_cmd(cmd[0], envp);
	process_child(pipex, ONE);
	if (cmd_path && access(cmd_path, F_OK | X_OK) == 0)
	{
		if (cmd_path && execve(cmd_path, cmd, envp) < 0)
		{
			free_and_close(pipex.pipefd, cmd, cmd_path);
			ft_error(argv[2], 127, "command not found");
		}
	}
	else
	{
		free_and_close(pipex.pipefd, cmd, cmd_path);
		ft_error(argv[2], 1, strerror(errno));
	}
}

static void	process_child_two(t_pipex pipex, char **argv, char **envp)
{
	char	**cmd;
	char	*cmd_path;

	pipex.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		ft_error(argv[4], 1, strerror(errno));
	cmd = ft_split(argv[3], ' ');
	cmd_path = get_cmd(cmd[0], envp);
	if (cmd_path && access(cmd_path, F_OK | X_OK) == 0)
	{
		process_child(pipex, TWO);
		if (execve(cmd_path, cmd, envp) < 0)
		{
			free_and_close(pipex.pipefd, cmd, cmd_path);
			ft_error(argv[3], 127, "command not found");
		}
	}
	else
	{
		free_and_close(pipex.pipefd, cmd, cmd_path);
		ft_error(argv[3], 1, strerror(errno));
	}
}

void	process_child(t_pipex pipex, int process)
{
	if (process == ONE)
	{
		dup2(pipex.pipefd[1], STDOUT_FILENO);
		dup2(pipex.infile, STDIN_FILENO);
		close(pipex.infile);
	}
	else if (process == TWO)
	{
		dup2(pipex.pipefd[0], STDIN_FILENO);
		dup2(pipex.outfile, STDOUT_FILENO);
		close(pipex.outfile);
	}
	ft_close_pipefd(pipex.pipefd);
}

int	ft_process(t_pipex pipex, char **argv, char **envp)
{
	int	status;

	status = 0;
	pipex.pid = fork();
	if (pipex.pid < 0)
		ft_error(ERR_FORK, 1, strerror(errno));
	else if (pipex.pid == 0)
		process_child_one(pipex, argv, envp);
	pipex.pid = fork();
	if (pipex.pid < 0)
		ft_error(ERR_FORK, 1, strerror(errno));
	else if (pipex.pid == 0)
		process_child_two(pipex, argv, envp);
	ft_close_pipefd(pipex.pipefd);
	waitpid(-1, &status, WUNTRACED);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (status);
}
