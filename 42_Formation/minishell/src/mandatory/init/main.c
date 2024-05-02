/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:18:31 by andrefil          #+#    #+#             */
/*   Updated: 2024/05/02 00:59:55 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void	initialize_data(t_token **token_list, t_ast **ast_list)
{
	*token_list = malloc(sizeof(t_token *) + 1);
	*ast_list = malloc(sizeof(t_ast *) + 1);
	*token_list = NULL;
	*ast_list = NULL;
}

int		get_input(void)
{
	char		*input;
	t_token		*token_list;
	t_ast		*ast_list;

	initialize_data(&token_list, &ast_list);
	input = readline("minishell>: ");
	if (!ft_strncmp(input, "", 1))
		return (0);
	add_history(input);
	if (syntax_checker(input))
	{
		if (build_token(input, &token_list) == ERROR)
			return (0);
		scan_token_list(&token_list, &ast_list);
		if (call_builtins(input))
			return (1);
		if (ft_strncmp(input, "exit", 5) == 0)
			return (END);
		free (input);
	}
	else
	{
		ft_putendl_fd("Error in syntax.", 2);
		return (0);
	}
	//free_data(&ast_list, &token_list); -> vou arrumar ainda, tá dando segfault (HAHAHAHAHA);
	return (1);
}

int	main(void)
{
	while (1)
	{
		if (get_input() == END)
			break ;
	}
	rl_clear_history();
	return (0);
}
