/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:38:37 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/23 23:51:18 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_flags(va_list args, const char format)
{
	if (format == '%')
		return (ft_putchar('%', 1));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *), 1));
	else if (format == 'd')
		return (ft_itoa(va_arg(args, int)));
	else if (format == 'c')
		return (ft_putchar(va_arg(args, int), 1));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format == 'p')
		return (ft_atoihexa(va_arg(args, unsigned int)));
	else if (format == 'x' )
		return (ft_puthexa(va_arg(args, unsigned int), format));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	index;
	va_list	args;
	int		len;

	len = 0;
	index = 0;
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			len += ft_print_flags(args, format[index + 1]);
			index++;
		}
		else
			len += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (len);
}

int	main()
{

	return (0);
}
