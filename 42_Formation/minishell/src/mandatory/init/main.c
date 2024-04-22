/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:18:31 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/21 21:03:07 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../libs/libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int	main(void)
{
	t_data	*data;
	t_node	*last_lst;

	data = malloc(sizeof(t_data *) * 1);
	data->cmd = malloc(sizeof(t_llist) *1);
	while (1)
	{
		add_last_node(&data->cmd->list, create_node(readline("minishell: ")));
		last_lst = last_node(&data->cmd->list);
//		ft_putendl_fd((char *)data->cmd->list->content, 1);
		if (ft_strncmp(last_lst->content, "", 1))
			add_history(last_lst->content);
		if (ft_strncmp(last_lst->content, "clear", 6) == 0)
			ft_putendl_fd("\e[2J\e[H", 1);
		else if (ft_strncmp(last_lst->content, "pwd", 4) == 0)
			put_pwd();
		else if (ft_strncmp(last_lst->content, "cd", 2) == 0)
			change_dir(last_lst->content);
		else if (ft_strncmp(last_lst->content, "exit", 5) == 0)
			break ;
	}
	rl_clear_history();
	return (0);
}
