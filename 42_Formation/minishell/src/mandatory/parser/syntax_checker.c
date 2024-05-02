/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:09:40 by andrefil          #+#    #+#             */
/*   Updated: 2024/05/03 01:18:03 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static int	check_quots(const char *input)
{
	char	quots;
	int		index;
	
	index = 0;
	quots = '\0';
	while (input[index] != '\0')
	{
		if (input[index] == '"' || input[index] == '\'')
		{
			if (quots == 0)
				quots = input[index];
			else if (quots == input[index])
				quots = 0;
		}
		index++;
	}
	if (quots)
		return (0);
	return (1);
}

static int	check_pipe(const char *input)
{
	int	index;
	int	double_q;
	int	single_q;
	int	valid;

	index = 0;
	double_q = 0;
	single_q = 0;
	valid = 0;
	if (input[index] == '|')
		return (0);
	while (input[index] != '\0')
	{
		if (input[index] == '\'')
			single_q++;
		else if (input[index] == '"')
			double_q++;
		if (input[index] == '|' && !(single_q % 2) && !(double_q %2))
		{
			if (valid)
				return (0);
			valid = 1;
		}
		else if (is_space(input[index]))
			valid = 0;
		index++;
	}
	if (valid)
		return (0);
	return (1);
}

static int	check_redirect(char const *input)
{
	int	index;
	int	double_q;
	int	single_q;

	index = 0;
	double_q = 0;
	single_q = 0;
	while (input[index] != '\0')
	{
		if (input[index] == '\'')
			single_q++;
		else if (input[index] == '"')
			double_q++;
		if ((input[index] == '>' || input[index] == '<') && (single_q % 2 == 0) && (double_q % 2 == 0))
		{
			if (input[index] != input[index + 1])
			{
				if (!is_space(input[index + 1]))
				{
					if (ft_isalnum(input[index + 1]))
						return (1);
					else
						return (0);
				}
			}
		}
		index++;
	}
	return (1);
}

int		syntax_checker(const char *input)
{
	if (!check_quots(input))
		return (0);
	if (!check_pipe(input))
		return (0);
	if (!check_redirect(input))
		return (0);
	return (1);
}
