/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:22:57 by mavitori          #+#    #+#             */
/*   Updated: 2024/05/02 01:00:46 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

t_token	*build_redirect_token(int *i, char *cmd_line)
{
	t_token		*token;
	char		c;

	if (cmd_line[*i] == '<' || cmd_line[*i] == '>')
		c = cmd_line[*i];
	else
		return (NULL);

	if (cmd_line[*i] == c)
	{
		if (cmd_line[(*i) + 1] == c && cmd_line[(*i) + 2] == c)
		{
			printf("Syntax error near unexpected token \'%c\'", c);
			return (NULL);
		}
		else if (cmd_line[(*i) + 1] == c)
			token = token_lstnew(ft_strndup(&cmd_line[(*i)++], 2), DLESS);
		else
			token = token_lstnew(ft_strndup(&cmd_line[*i], 1), LESS);
	}
	else
		token = NULL;
	return (token);
}

t_token	*build_word_token(int *i, char *cmd_line)
{
	t_token		*token;
	int			size;

	size = *i;
	while (ft_isspace(cmd_line[size]) == 0 && cmd_line[size])
		size++;
	token = token_lstnew(ft_strndup(&cmd_line[*i], size - *i), WORD);
	*i = size;
	return (token);
}

t_token	*build_expansion_token(int *i, char *cmd_line)
{
	t_token		*token;
	int			size;

	size = *i;
	size++;
	while (ft_isalpha(cmd_line[size]) != 0 || cmd_line[size] == '_')
		size++;
	token = token_lstnew(ft_strndup(&cmd_line[*i], size - *i), EXPANSION);
	*i = size;
	return (token);
}

t_token	*build_quote_token(int *i, char *cmd_line)
{
	t_token	*token;
	int			size;
	char		quote;

	size = *i;
	quote = cmd_line[size];
	size++;
	while (cmd_line[size] && cmd_line[size] != quote)
		size++;
	if (!cmd_line[size])
		return (NULL);
	else
		size++;
	token = token_lstnew(ft_strndup(&cmd_line[*i], size - *i), WORD);
	*i = size;
	return (token);
}

int	build_token(char *cmd_line, t_token **token_list)
{
	t_token		*token;
	int			i;

	i = 0;
	while (cmd_line[i])
	{
		token = NULL;
		if (cmd_line[i] == '<' || cmd_line[i] == '>')
		{
			token = build_redirect_token(&i, cmd_line);
			if (token == NULL)
				return (ERROR);
		}
		else if (cmd_line[i] == '|')
			token = token_lstnew(ft_strndup(&cmd_line[i], 1), PIPE);
		else if (cmd_line[i] == '$')
			token = build_expansion_token(&i, cmd_line);
		else if (cmd_line[i] == '\'' || cmd_line[i] == '\"')
		{
			token = build_quote_token(&i, cmd_line);
			if (token == NULL)
				return (ERROR);
		}
		else if (ft_isspace(cmd_line[i]) == 0)
			token = build_word_token(&i, cmd_line);
		if (token != NULL)
			token_lstadd_back(token_list, token);
		if (cmd_line[i])
			i++;
	}
	return (TRUE);
}
