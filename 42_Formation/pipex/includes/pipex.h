/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:02:27 by andrefil          #+#    #+#             */
/*   Updated: 2024/02/05 13:49:07 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <libft.h>
# include <ft_printf.h>

# define ERR_INPUT "Invalid number of arguments"
# define ERR_PIPEFD "pipe"
# define ERR_CMD "Command not found"
# define ERR_FORK "Fork error"
# define ERR_ENVP "Wrong arguments. try: ./pipex file1 cmd1 cmd2 file2"
# define ERR_ARGS "Quantities args wrong. try: ./pipex file1 cmd1 cmd2 file2"
# define ONE 1
# define TWO 2

typedef struct s_cmd	t_cmd;
struct	s_cmd
{
	char	*bin;
	char	**flag;
};

typedef struct s_pipex	t_pipex;
struct	s_pipex
{
	pid_t	pid;
	int		pipefd[2];
	int		infile;
	int		outfile;
	char	**path;
	int		process;
	int		status;
	t_cmd	*cmd;
};

// Functions about strings
char	**split_env(char **envp);
void	get_cmd(t_pipex **pipex, char *argv);
void	valid_sign(char *argv, char ***split_cmd);

// Functions about process
int		ft_process(t_pipex *pipex, char **argv, char **envp);
void	process_child(t_pipex *pipex, char **argv, int process, char **envp);

// functions close and free
void	free_cmd(t_cmd *cmd);
void	free_pipex(t_pipex *pipex);
void	free_matrix(char ***matrix);
void	ft_close_pipefd(int *pipefd);
void	ft_error(t_pipex *pipex, char *str, char *error, int status);

#endif
