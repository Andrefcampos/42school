# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 01:38:41 by andrefil          #+#    #+#              #
#    Updated: 2023/11/23 02:31:34 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c
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
