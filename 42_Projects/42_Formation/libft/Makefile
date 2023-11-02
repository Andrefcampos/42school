# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 11:57:28 by andrefil          #+#    #+#              #
#    Updated: 2023/11/02 04:34:01 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libft.a
INCLUDES = libft.h
CFLAGS = -Wall -Wextra -Werror
FILES = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_strdup.c\
	ft_calloc.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c
OBJS = $(FILES:.c=.o)
FILES_BONUS = ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c
OBJS_BONUS = $(FILES_BONUS:.c=.o)

all: $(NAME)

.c.o:
	${CC} -I $(INCLUDES) ${FLAGS} -c $< -o ${<:.c=.o}
	ar rcs $(NAME) ${<:.c=.o}

$(NAME): $(OBJS)

bonus: $(OBJS_BONUS)

$(OBJS_BONUS): $(FILES_BONUS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
