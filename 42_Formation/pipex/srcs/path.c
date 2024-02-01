/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:26:39 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/01 17:03:13 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_strrplc(char *str, char old, char new)
{
	size_t	index;

	if (!str)
		return ;
	index = 0;
	while (str[index])
	{
		if (str[index] == old)
			str[index] = new;
		index++;
	}
}

void	valid_sign(char *argv, char ***split_cmd)
{
	int	index;
	char	signal;

	index = 0;
	signal = 0;
	while (argv && argv[index])
	{
		if (signal && argv[index] == signal)
			signal = 0;
		if (!signal && (argv[index] == '\"' \
			|| argv[index] == '\''))
		{
			signal = argv[index];
			argv[index] = 32;
		}
		else if (signal && argv[index] == 32)
			argv[index] = 26;
		index++;
	}
	*split_cmd = ft_split(argv, 32);
	index = 0;
	while (*split_cmd[index])
		ft_strrplc(**(split_cmd[index++]), 26, 32);
	free(argv);
}

void	get_cmd(t_pipex **pipex, char *argv)
{
	t_cmd	*cmd;
	char	**parse_cmd;

	if (!pipex || !argv)
		return ;
	cmd = (t_cmd *) ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return ;
	valid_sign(ft_strdup(argv), &parse_cmd);
	cmd->bin = *parse_cmd;
	cmd->flag = parse_cmd;
	(*pipex)->cmd = cmd;
}
