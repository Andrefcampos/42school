/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_here_doc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:39:56 by mavitori          #+#    #+#             */
/*   Updated: 2024/05/02 23:20:53 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include <stdio.h>

int	execute_here_doc(t_ast *operator)
{
	// DLESS, - here doc
	// left = command
	// right = delimiter
	printf("\nExecutar here doc aqui!\n");
	if (operator->left != NULL)
		printf("\nEsquerda=commando: %s\n", operator->left->content);
	if (operator->right != NULL)
		printf("\nDireita=delimiter: %s\n", operator->right->content);
	return (OK);
}
