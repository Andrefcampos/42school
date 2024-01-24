/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:26:39 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/24 14:48:14 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char	*find_env(char **envp)
{
	int	index;

	index = 0;
	while (ft_strncmp("PATH", envp[index], 4))
		index++;
	return (envp[index] + 5);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*path;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, '/');
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		paths++;
	}
	return (NULL);
}

void	process_child(t_pipex pipex, char *argv, char **envp, int child)
{
	if (child == ONE)
	{
		dup2(pipex.pipefd[1], 1);
		close(pipex.pipefd[0]);
		dup2(pipex.infile, 0);
		pipex.cmd_args = ft_split(*argv, ' ');
	}
	if (child == TWO)
	{
		dup2(pipex.pipefd[0], 0);
		close(pipex.pipefd[1]);
		dup2(pipex.outfile, 1);
		pipex.cmd_args = ft_split(*argv, ' ');
	}
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_matrix(pipex.cmd_paths);
		free_matrix(pipex.cmd_args);
		ft_error(ERR_CMD, 2);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

int	fork_process(t_pipex pipex, char **av, char **evp)
{
	pipex.paths = find_env(evp);
	pipex.cmd_paths = ft_split(pipex.paths, 0x3A);
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		return(ERR_FORK);
	else if (pipex.pid1 == 0)
	{
		pipex.infile = open(av[2], O_RDONLY);
		if (pipex.infile < 0)
			return (ft_error(ERR_INFILE, 2));
		process_child(pipex, av, evp, ONE);
	}
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		return (ERR_FORK);
	else if (pipex.pid2 == 0)
	{
		pipex.outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
		if (pipex.outfile < 0)
			return (ft_error(ERR_OUTFILE, 2));
		process_child(pipex, av, evp, TWO);
	}
	return (0);
}
