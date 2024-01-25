/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:57:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/25 20:08:44 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	process_child_one(t_pipex pipex, char **argv, char **envp)
{
	pid_t	pid;
	char	**cmd;
	char	*cmd_path;

	pid = fork();
	if (pid < 0)
		ft_error(ERR_FORK);
	if (pid == 0)
	{
		pipex.infile = open(argv[1], O_RDONLY);
		if (pipex.infile < 0)
			ft_error(ERR_INFILE);
		cmd = ft_split(argv[2], ' ');
		cmd_path = get_cmd(cmd[0], envp);
		if (cmd[0] != NULL && cmd_path)
		{
			process_child(pipex, ONE);
			execve(cmd_path, cmd, envp);
		}
		else
		{
			free_matrix(cmd);
			ft_not_cmd(pipex.pipefd, pipex.infile, cmd);
		}
	}
}

static void	process_child_two(t_pipex pipex, char **argv, char **envp)
{
	pid_t	pid;
	char	**cmd;
	char	*cmd_path;

	pid = fork();
	if (pid < 0)
		ft_error(ERR_FORK);
	if (pid == 0)
	{
		pipex.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex.outfile < 0)
			ft_error(ERR_INFILE);
		cmd = ft_split(argv[3], ' ');
		cmd_path = get_cmd(cmd[0], envp);
		if (cmd[0] != NULL && cmd_path)
		{
			process_child(pipex, TWO);
			execve(cmd_path, cmd, envp);
		}
		else
		{
			free_matrix(cmd);
			ft_not_cmd(pipex.pipefd, pipex.infile, cmd);
		}
	}
}

void	process_child(t_pipex pipex, int process)
{
	if (process == ONE)
	{
		dup2(pipex.pipefd[1], STDOUT_FILENO);
		close(pipex.pipefd[0]);
		dup2(pipex.infile, STDIN_FILENO);
		close(pipex.infile);
	}
	else if (process == ONE)
	{
		dup2(pipex.pipefd[0], STDIN_FILENO);
		close(pipex.pipefd[1]);
		dup2(pipex.outfile, STDOUT_FILENO);
		close(pipex.outfile);
	}
}

int	ft_process(t_pipex pipex, char **argv, char **envp)
{
	process_child_one(pipex, argv, envp);
	process_child_two(pipex, argv, envp);
	close(pipex.infile);
	close(pipex.outfile);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	return (0);
}
