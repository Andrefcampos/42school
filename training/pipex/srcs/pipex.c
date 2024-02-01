/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:43:27 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/30 15:58:30 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putendl_fd(ERR_ARGS, 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipex.pipefd) < 0)
		ft_error(ERR_PIPEFD, 1, strerror(errno));
	return (ft_process(pipex, argv, envp));
}
