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

void	search_paths(char **paths, char **envp)
{
	int	index;

	index = 0;
	while (!ft_strncmp(*envp[index++], "PATH", 4));
		;
	paths = ft_split(*envp[index] + 5, ':');
}

void	get_cmd(t_pipex pipex, char **envp)
{
	int	index;

	index = 0;
	search_paths(pipex.paths, envp);
	while (pipex.paths[index])
	{
		pipex.path = ft_strjoin(pipex.paths[index], '/');
		pipex.path = ft_strjoin(pipex.path, pipex.cmd);
		if (!access(pipex.path, F_OK))
		{
			free_matrix(pipex.paths);
			return (pipex.path);
		}
		free(pipex.path);
		index++;
	}
	free_matrix(pipex.paths);
}
