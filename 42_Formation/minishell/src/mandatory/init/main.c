/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:18:31 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/16 20:56:16 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../libs/libft/libft.h"
#include <stdlib.h>

int	main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data *) * 1);
	data->cmd = malloc(sizeof(t_llist) *1);
	data->cmd->list = create_node("ola");
	ft_putstr_fd((char *)data->cmd->list->content, 1);

	return (0);
}
