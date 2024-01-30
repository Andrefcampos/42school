/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:26:39 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/30 15:29:02 by andrefil         ###   ########.fr       */
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
	char	*temp;
	char	*path;
	char	**paths;
	int		index;

	index = 0;
	paths = find_env(envp);
	while (paths[index])
	{
		temp = ft_strjoin(paths[index], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_matrix(&paths);
			return (path);
		}
		free(path);
		index++;
	}
	free_matrix(&paths);
	return (NULL);
}
