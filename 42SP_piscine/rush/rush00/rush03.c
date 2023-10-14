/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taferrei <taferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 08:26:36 by taferrei          #+#    #+#             */
/*   Updated: 2023/08/20 21:54:39 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char n);

void	f_conditional(int col, int row, int x, int y)
{
	if ((y == 1 && x == 1) || (y == 1 && x == row))
	{
		ft_putchar('A');
	}
	else if ((y == col && x == 1) || (y == col && x == row))
	{
		ft_putchar('C');
	}
	else if ((x == 1 && y > 1) || (x == row && y < col))
	{
		ft_putchar('B');
	}
	else if ((x > 1 && y == 1) || (x < row && y == col))
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int col, int row)
{
	int	x;
	int	y;

	x = 1;
	if (col > 0 && row > 0)
	{
		while (x <= row)
		{
			y = 1;
			while (y <= col)
			{
				f_conditional(col, row, x, y);
				y++;
			}
			ft_putchar('\n');
			x++;
		}
	}
}
