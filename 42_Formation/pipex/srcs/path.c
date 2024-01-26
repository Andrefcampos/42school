/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:26:39 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/25 19:50:08 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_env(char **envp)
{
	char	**paths;
	int		index;

	index = 0;
	while (ft_strncmp("PATH", envp[index], 4))
		index++;
	paths = ft_split(envp[index] + 5, ':');
	return (paths);
}

char	*get_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**paths;
	int		index;

	index = 0;
	paths = find_env(envp);
	while (paths[index])
	{
		path = ft_strjoin(paths[index], "/");
		path = ft_strjoin(path, cmd);
		if (!access(path, F_OK | X_OK))
		{
			free_matrix(paths);
			return (path);
		}
		free(path);
		index++;
	}
	free_matrix(paths);
	return (0);
}
