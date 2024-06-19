/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:09:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/18 18:12:10 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_av(char *arg)
{
	int	index;

	if (!arg)
		return (0);
	index = 0;
	while(arg[index])
	{
		if (arg[index] < 48 || arg[index++] > 57)
			return (0);
	}
	return (1);
}

int	validation_args(int ac, char **av)
{
	int	index;

	index = 1;
	if (ac < 5 || ac > 7)
		return (0);
	while (av[index])
	{
		if (!check_av(av[index++]))
			return (0);
	}
	return (1);
}
