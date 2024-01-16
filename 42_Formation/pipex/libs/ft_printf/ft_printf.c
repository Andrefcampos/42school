/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:38:37 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/30 19:11:02 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flags(va_list args, const char format)
{
	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 'd')
		return (ft_putdigit(va_arg(args, int), 10, OFF));
	else if (format == 'i')
		return (ft_putdigit(va_arg(args, int), 10, OFF));
	else if (format == 'u')
		return (ft_putdigit(va_arg(args, unsigned int), 10, OFF));
	else if (format == 'x')
		return (ft_putdigit(va_arg(args, unsigned int), 16, OFF));
	else if (format == 'X' )
		return (ft_putdigit(va_arg(args, unsigned int), 16, ON));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
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
	if (format == NULL)
		return (-1);
	while (format[index])
	{
		if (format[index] == '%')
			len += ft_print_flags(args, format[++index]);
		else
			len += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (len);
}
