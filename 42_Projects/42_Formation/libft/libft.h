/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:41:34 by andrefil          #+#    #+#             */
/*   Updated: 2023/10/26 00:28:11 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, int len);
char	*ft_strnstr(const char *big, const char *little, int len);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strchr(const char *str, int ch);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
void	*ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_memcpy(void *dest, const void *src, int num);
void	*ft_memmove(void *dest, const void *src, int num);
void	*ft_memchr(const void *str, int ch, int num);
void	*ft_memset(void *str, int ch, int num);
void	*ft_calloc(int n, int size);
void	ft_bzero(void *str, int num);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strncmp(const char *str1, const char *str2, int num);
int		ft_memcmp(const void *s1, const void *s2, int n);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
int		ft_isalpha(int ch);
int		ft_isdigit(int ch);
int		ft_isalnum(int ch);
int		ft_isascii(int ch);
int		ft_isprint(int ch);
int		ft_atoi(const char *str);
int		ft_strlcpy(char *dest, const char *src, int size);
int		ft_strlcat(char *dest, const char *src, int size);
int		ft_strlen(const char *str);

#endif
