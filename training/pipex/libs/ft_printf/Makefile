# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 01:38:41 by andrefil          #+#    #+#              #
#    Updated: 2024/01/17 21:29:18 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = cc
INCLUDES = ft_printf.h
FLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c \
	ft_printf_utils.c
OBJS = $(FILES:.c=.o)

all: $(NAME)

.c.o:
	$(CC) -I $(INCLUDES) $(FLAGS) -c $< -o $(<:.c=.o)
	ar rcs $(NAME) $(<:.c=.o)

$(NAME): $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re
.SILENT:
