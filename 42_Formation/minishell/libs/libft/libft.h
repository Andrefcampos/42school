/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:41:34 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/17 23:53:59 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

typedef struct s_list	t_list;
struct s_list
{
	void			*content;
	t_list			*next;
};

// String functions:
int		ft_strncmp(const char *str1, const char *str2, size_t num);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
int		ft_isalpha(int ch);
int		ft_isdigit(int ch);
int		ft_isalnum(int ch);
int		ft_isascii(int ch);
int		ft_isprint(int ch);
int		ft_atoi(const char *str);
long	ft_atol(const char *nstr);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strchr(const char *str, int ch);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *src);
char	*ft_itoa(int n);

// Memory functions:
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t num);
void	*ft_memchr(const void *str, int ch, size_t num);
void	*ft_memset(void *str, int ch, size_t num);
void	ft_bzero(void *str, size_t num);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// Alloc functions:
void	*ft_calloc(size_t n, size_t size);

// List functions:
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_lstadd_back(t_list **lst, t_list *node);

#endif
