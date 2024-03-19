/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:28:40 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/18 19:59:46 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int	check_args(char **av)
{
	int	y;
	int	x;

	y = 1;
	if (av[y] == NULL || ft_strlen(av[y]) == 0 || ft_strlen(av[y]) > 11)
		return (0);
	while (av[y])
	{
		x = 0;
		while (av[y][x])
		{
			if (av[y][0] == '-' || av[y][0] == '+')
			{
				if (!ft_isdigit(av[y][1]))
					return (0);
			}
			else if (!ft_isdigit(av[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	if (ft_strlen(av[y - 1]) == 0)
		return (0);
	return (1);
}

int	check_args_dup(char **av)
{
	int		y;
	int		x;

	y = 1;
	while (av[y])
	{
		if (ft_strlen(av[y]) > 11 && ((ft_atol(av[y]) > INT_MAX \
			|| ft_atol(av[y]) < INT_MIN)))
			return (0);
		x = y + 1;
		while (av[x])
		{
			if (ft_atol(av[y]) == ft_atol(av[x]))
				return (0);
			x++;
		}
		y ++;
	}
	return (1);
}

void	validate_args(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && check_args(av)))
		exit(EXIT_FAILURE);
	else if (!check_args(av) || !check_args_dup(av))
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
}

int	check_sort(t_node **head)
{
	t_node	*temp;
	t_node	*current_node;

	if (!*head || !(*head)->next)
		return (1);
	current_node = *head;
	while (current_node)
	{
		temp = current_node->next;
		while (temp)
		{
			if (current_node->num > temp->num)
				return (0);
			temp = temp->next;
		}
		current_node = current_node->next;
	}
	return (1);
}
