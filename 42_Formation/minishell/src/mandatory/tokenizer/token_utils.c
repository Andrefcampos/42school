/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:36:44 by mavitori          #+#    #+#             */
/*   Updated: 2024/05/02 01:01:05 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	*ft_strndup(const char *src, int size)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = size + 1;
	dest = ft_calloc(len, sizeof(char));
	if (!dest)
		return (NULL);
	while(i + 1 < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

t_token	*token_lstnew(char *content, tokens type)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->token = type;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	token_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*current;

	if (*lst == NULL && new != NULL)
	{
		*lst = new;
		return ;
	}
	if (new != NULL)
	{
		current = *lst;
		if (current != NULL)
		{
			while (current->next != NULL)
				current = current->next;
			current->next = new;
			new->prev = current;
		}
		else
			*lst = new;
	}
}

t_token	*token_lstlast(t_token *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

void	token_lstclear(t_token **lst)
{
	t_token	*current;
	t_token	*next;

	if (*lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free (current->content);
		free (current);
		current = next;
	}
	*lst = NULL;
}
