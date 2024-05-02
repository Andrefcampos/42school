/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:39:33 by mavitori          #+#    #+#             */
/*   Updated: 2024/05/02 23:05:04 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	execute_pipe(t_ast *operator)
{
	// PIPE, - pipe
	// left = input do pipe
	// right = output do pipe
	printf("\nExecutar PIPE aqui!\n");
	if (operator->left != NULL)
		printf("\nEsquerda=input: %s\n", operator->left->content);
	if (operator->right != NULL)
		printf("\nDireita=right: %s\n", operator->right->content);
	return (OK);
}
