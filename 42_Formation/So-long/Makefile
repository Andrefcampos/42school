# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 14:47:49 by andrefil          #+#    #+#              #
#    Updated: 2024/01/14 10:26:51 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so-long
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -g3 -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./includes -I $(LIBMLX)/include -I ./lib/libft -I ./lib/ft_printf
LIBS	:= ./lib/libft/libft.a ./lib/ft_printf/ft_printf.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

OBJS_DIR   := obj/
FILES_DIR := src/

FILES	:= $(addprefix $(FILES_DIR), actions_moves.c \
			flood_fill.c \
			free_end_map.c \
			hooks_maps.c \
			convert_img.c \
			init_game.c \
			init_vars.c \
			main.c \
			parse_map.c \
			print_img.c \
			print_img2.c \
			read_map.c)

OBJS	+= ${FILES:%.c=$(OBJS_DIR)%.o}

all: libmlx printf libft $(NAME)

printf:
	$(MAKE) -C lib/ft_printf

libft:
	$(MAKE) -C lib/libft

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJS_DIR)%.o: %.c
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) fclean -C lib/ft_printf
	@$(MAKE) fclean -C lib/libft
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
.SILENT:
