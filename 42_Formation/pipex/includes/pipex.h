/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:02:27 by andrefil          #+#    #+#             */
/*   Updated: 2024/01/25 22:52:54 by andrefil         ###   ########.fr       */
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
# include <libft.h>
# include <printf.h>

# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_INFILE "Infile.\n"
# define ERR_OUTFILE "Outfile.\n"
# define ERR_PIPEFD "Pipefd error.\n"
# define ERR_CMD "Command not found.\n"
# define ERR_FORK "Fork error.\n"
# define ERR_ENVP "Wrong arguments. try: ./pipex file1 cmd1 cmd2 file2.\n"
# define ONE 1
# define TWO 2

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	int		infile;
	int		outfile;
}				t_pipex;

void	free_matrix(char ***matrix);
char	**find_env(char **envp);
void	ft_not_cmd(int *pipefd, int fd);
int		ft_process(t_pipex pipex, char **argv, char **envp);
void	process_child(t_pipex pipex, int process);
void	ft_error(char *str);
char	*get_cmd(char *cmd, char **envp);

#endif
