/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:39:09 by mavitori          #+#    #+#             */
/*   Updated: 2024/05/02 23:23:41 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>


char	**get_command_args(char *content)
{
	char	**remove_quotes;
	char	**cmd_args;

	remove_quotes = NULL;
	cmd_args = NULL;
	if (content[0] == '\'')
		remove_quotes = ft_split(content, '\'');
	else if (content[0] == '\"')
		remove_quotes = ft_split(content, '\"');
	if (remove_quotes != NULL)
	{
		cmd_args = ft_split(remove_quotes[0], ' ');
		free(remove_quotes);
	}
	else
		cmd_args = ft_split(content, ' ');

	return (cmd_args);
}

int	execute_command(char *content)
{
	char	**cmd_args;
	char	**args;
	char	*path;
	int		i;

	cmd_args = get_command_args(content);
	path = ft_strdup("/bin/");
	if (path == NULL)
	{
		perror("ft_strdup");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (cmd_args[i])
		i++;
	args = (char **)malloc((i + 2) * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc");
		free(path);
		exit(EXIT_FAILURE);
	}
	i = 0;
	args[0] = ft_strjoin(path, cmd_args[0]);
	while (cmd_args[i])
	{
		args[i + 1] = cmd_args[i];
		i++;
	}
	args[i + 1] = NULL;
	if (execve(args[0], &args[1], __environ) == -1)
	{
		perror("execve");
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
		free(path);
		free(cmd_args);
		return (ERROR);
	}
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	free(cmd_args);
	free(path);
	return (TRUE);
}
