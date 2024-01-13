/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:19:42 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/28 13:46:55 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[len])
	{
		ft_putchar(s[len]);
		len++;
	}
	return (len);
}

int	ft_putdigit(long long n, int base, int key)
{
	int	len;

	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putdigit(-n, base, key) + 1);
	}
	else if (n < base)
	{
		if (key == ON)
			return (ft_putchar(HEX_UP[n]));
		return (ft_putchar(HEX_LOW[n]));
	}
	else
	{
		len = ft_putdigit(n / base, base, key);
		return (len + ft_putdigit(n % base, base, key));
	}
}

int	ft_put_ptr(unsigned long long n)
{
	int	len;

	len = 0;
	if (n < 16)
		return (ft_putchar(HEX_LOW[n]));
	else
	{
		len = ft_put_ptr(n / 16);
		return (len + ft_put_ptr(n % 16));
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (len += write(1, "(nil)", 5));
	else
	{
		len += write(1, "0x", 2);
		len += ft_put_ptr(ptr);
	}
	return (len);
}
