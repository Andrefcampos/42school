# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 14:47:49 by andrefil          #+#    #+#              #
#    Updated: 2024/01/14 06:44:27 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so-long
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -g3 -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./includes -I $(LIBMLX)/include -I ./lib/libft -I ./lib/ft_printf
LIBS	:= ./lib/libft/libft.a ./lib/ft_printf/ft_printf.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= ./src/*c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

# fclean: clean
# 	clean $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
