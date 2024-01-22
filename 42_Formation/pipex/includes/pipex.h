/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:02:27 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/19 20:47:17 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/libft.h"

# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_INFILE "Infile.\n"
# define ERR_OUTFILE "Outfile.\n"
# define ERR_PIPEFD "Pipefd error.\n"
# define ERR_CMD "Command not found.\n"
# define ERR_FORK "Fork error.\n"
# define ERR_ENVP "Wrong arguments. try: ./pipex file1 cmd1 cmd2 file2.\n"

typedef struct	s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	char	*paths;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		infile;
	int		outfile;
}				t_pipex;

void	ft_error(char *str);
void	free_matrix(char **matrix);

#endif
