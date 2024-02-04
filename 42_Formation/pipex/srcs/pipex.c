/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:43:27 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/03 21:10:16 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static t_pipex	*ft_pipex(void)
{
	static t_pipex	pipex;

	return (&pipex);
}

char	**split_env(char **envp)
{
	int		index;

	if (!envp)
		return (0);
	index = 0;
	while (ft_strncmp(envp[index], "PATH", 4) != 0)
		index++;
	if (!(*envp))
		return (0);
	return (ft_split(envp[index], 58));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc != 5)
	{
		ft_putendl_fd(ERR_ARGS, 2);
		exit (EXIT_FAILURE);
	}
	pipex = ft_pipex();
	pipex->path = split_env(envp);
	pipex->n_args = argc - 1;
	pipex->file1 = ft_strdup(argv[1]);
	pipex->file2 = ft_strdup(argv[4]);
	return (ft_process(pipex, argv, envp));
}
