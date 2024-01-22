/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:26:39 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/19 20:48:29 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char	*find_env(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4));
		envp++;
	return (*envp + 5);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*temp;
	char	*path;

	while (*paths)
	{
		temp = ft_strjoin(*paths, 0x2F);
		path = ft_strjoin(tmp, cmd);
		free(temp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		paths++;
	}
	return (NULL);
}

void	process_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.pipefd[1], 1);
	close(pipex.pipefd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], 0x20);
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

