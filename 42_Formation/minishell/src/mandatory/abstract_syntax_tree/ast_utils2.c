/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:57:55 by andrefil          #+#    #+#             */
/*   Updated: 2024/05/02 00:59:27 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <fcntl.h>

returns	is_file(const char *content)
{
	int	fd;

	fd = open(content, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

type_ast	type_check(char *content, tokens token)
{
	type_ast	ast_type;

	if (token == WORD)
	{
		if (content[0] == '"' || content[0] == '\'')
			ast_type = STRING;
		else if (is_file(content))
			ast_type = FILENAME;
		else
			ast_type = COMMAND;
	}
	else
		ast_type = token - 10;
	return (ast_type);
}
