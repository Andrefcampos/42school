/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:26:39 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/24 18:48:03 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	find_env(char **envp, char **cmd_paths)
{
	int	index;

	index = 0;
	while (ft_strncmp("PATH", envp[index], 4))
		index++;
	cmd_paths = ft_split(envp[index] + 5, ':');
}

char	*get_cmd(char **cmd_paths, char *cmd, char **envp)
{
	char	*path;
	int		index;

	find_env(envp, cmd_paths);
	index = 0;
	while (cmd_paths[index])
	{
		path = ft_strjoin(cmd_paths[index], "/");
		path = ft_strjoin(path, cmd);
		if (!access(path, F_OK | X_OK))
		{
			free_matrix(cmd_paths);
			return (path);
		}
		free(path);
		index++;
	}
	free_matrix(cmd_paths);
	return (NULL);
}
