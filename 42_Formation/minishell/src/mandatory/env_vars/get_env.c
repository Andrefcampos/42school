/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:04:48 by andrefil          #+#    #+#             */
/*   Updated: 2024/05/05 03:02:33 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

static char	*get_key(char *envp, int *len_key)
{
	char	*key;

	*len_key = 0;
	while (envp[*len_key] != '=')
		(*len_key)++;
	key = ft_strndup(envp, *len_key);
	*len_key += 1;
	return (key);
}

void	get_envp(t_env_var **envp)
{
	char	*key;
	char	*value;
	int		index;
	int		len_key;

	index = 0;
	len_key = 0;
	while (__environ[index])
	{
		key = get_key(__environ[index], &len_key);
		value = ft_strdup(__environ[index] + len_key);
		env_lstadd_back(envp, env_lstnew(key, value));
		index++;
		free (key);
		free (value);
	}
}
