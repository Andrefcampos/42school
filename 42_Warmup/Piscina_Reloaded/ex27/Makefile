# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 15:07:18 by andrefil          #+#    #+#              #
#    Updated: 2023/10/07 22:05:00 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_display_file
FLAGS = -Wall -Wextra -Werror
SRC = ./srcs/
HEADER = ./includes/
OBJ = $(FILES:$(SRC)%.c=%.o)
FILES = $(SRC)main.c $(SRC)ft_putchar.c $(SRC)ft_putstr.c $(SRC)ft_display_file.c
RM = rm -f

all: $(NAME)

%.o: $(SRC)%.c $(HEADER)*.h
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all

