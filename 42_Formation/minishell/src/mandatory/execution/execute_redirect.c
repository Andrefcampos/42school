/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:38:06 by mavitori          #+#    #+#             */
/*   Updated: 2024/05/02 23:20:31 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

void	execute_redirect(t_ast *operator, int file_fd, int redirection_flag)
{
	pid_t	pid;
	int	status;

	pid = fork();
	if (pid == -1)
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (dup2(file_fd, redirection_flag) == -1)
		{
			perror("Failed to redirect input/output");
			close(file_fd);
			exit(EXIT_FAILURE);
		}
		close(file_fd);
		execute_command(operator->content);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}

int	execute_redirect_input(t_ast *operator)
{
	// LESS, - redirect input; left = file; right = command; abrir o arquivo; dup2(input_fd, STDIN); usar STDIN para executar commando e salvar no STDOUT; execve();
	int	input_fd;

	input_fd = open(operator->right->content, O_RDONLY);
	if (input_fd == -1)
	{
		perror("Failed to open file");
		return (KO);
	}
	execute_redirect(operator->left, input_fd, STDIN_FILENO);
	close (input_fd);
	return (OK);
}

int	execute_redirect_output(t_ast *operator)
{
	// GREAT - redirect output; left = command; right = file; usar STDIN para executar commando e salvar no STDOUT; execve(); abrir o arquivo; dup2(output_fd, STDOUT);
	int		output_fd;

	output_fd = open(operator->right->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
	{
		perror("Failed to open file");
		return (KO);
	}
	execute_redirect(operator->left, output_fd, STDOUT_FILENO);
	close (output_fd);
	return (OK);
}

int	execute_redirect_append(t_ast *operator)
{
	// DGREAT, - append; left = command; right = file; usar STDIN para executar commando e salvar no STDOUT; execve(); abrir o arquivo; dup2(output_fd, STDOUT); diferença é o modo append
	int		output_fd;

	output_fd = open(operator->right->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (output_fd == -1)
	{
		perror("Failed to open file");
		return (KO);
	}
	execute_redirect(operator->left, output_fd, STDOUT_FILENO);
	close (output_fd);
	return (OK);
}
