/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:10:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/16 16:20:41 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_node	*create_node(char *str)
{
	t_node	*aux;

	if (!str)
		retunr (NULL);
	aux = malloc(sizeof(t_node) * 1);
	if (!aux)
		return (NULL);
	aux->content = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!aux->content)
	{
		free (aux);
		return (NULL);
	}
	ft_strcpy(aux->content, str);
	aux->prev = NULL;
	aux->next = NULL;
	return (aux);
}
