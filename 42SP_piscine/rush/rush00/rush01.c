/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taferrei <taferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 08:26:36 by taferrei          #+#    #+#             */
/*   Updated: 2023/08/20 22:02:03 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char n);

void	f_conditional(int col, int row, int x, int y)
{
	if ((y == 1 && x == 1) || (y == col && x == row && col != 1 && row != 1))
	{
		ft_putchar('/');
	}
	else if ((y == 1 && x == row) || (y == col && x == 1))
	{
		ft_putchar('\\');
	}
	else if ((x == 1 && y > 1) || (x == row && y < col))
	{
		ft_putchar('*');
	}
	else if ((x > 1 && y == 1) || (x < row && y == col))
	{
		ft_putchar('*');
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
