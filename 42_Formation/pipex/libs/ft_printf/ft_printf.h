/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 04:05:04 by andrefil          #+#    #+#             */
/*   Updated: 2023/11/28 13:42:56 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define ON 1
# define OFF 0

typedef struct s_list	t_list;
struct s_list
{
	char			content;
	struct s_list	*next;
};

int	ft_putchar(int c);
int	ft_putstr(const char *s);
int	ft_put_ptr(unsigned long long n);
int	ft_printf(const char *format, ...);
int	ft_print_ptr(unsigned long long ptr);
int	ft_putdigit(long long n, int base, int key);

#endif
