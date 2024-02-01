/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:43:27 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/01 16:55:37 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static t_pipex	*ft_pipex(void)
{
	static t_pipex	*pipex;

	return (&pipex);
}

char	**split_env(char **envp, char *str)
{
	size_t	size_str;

	if (!envp || !str)
		return (0);
	size_str = ft_strlen(str);
	while (*envp && ft_strncmp(*envp, str, size_str))
		envp++;
	if (!(*envp))
		return (0);
	return (split(*envp + size_str + 1, 58));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc != 5)
		ft_error(ERR_ARGS , 1, 0);
	if (pipe(pipex->pipefd) < 0)
		ft_error(ERR_PIPEFD, 1, strerror(errno));
	pipex = ft_pipex();
	pipex->path = split_env(envp, "PATH");
	pipex->n_args = argc - 1;
	pipex->file1 = ft_strdup(argv[1]);
	pipex->file2 = ft_strdup(argv[4]);
	pipex->cmd_arg1 = ft_strdup(argv[2]);
	pipex->cmd_arg2 = ft_strdup(argv[3]);
	return (ft_process(pipex));
}
