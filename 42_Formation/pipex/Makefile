# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:42:20 by andrefil          #+#    #+#              #
#    Updated: 2024/01/16 20:25:16 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	pipex
CC			:=	cc
CFLAGS		:=	-Wextra -Wall -Werror -g3
LIB			:=	libs/
HEADERS		+=	$(addprefix $(LIB), \
				includes/ ft_printf/ \
				libft/ get_next_line/)

OBJS_DIR	:=	objs/
FILES_DIR	:=	srcs/

FILES		+=	$(addprefix $(FILES_DIR), \
				pipex.c)

OBJS		+=	$(FILES:%.c=$(OBJS_DIR)%.o)

all:		ft_printf libft $(NAME)

libft:
	@$(MAKE) -C $(LIB)libft

ft_printf:
	@$(MAKE) -C $(LIB)ft_printf

$(OBJS_DIR)%.o: %.c
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS)
	@rc rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) fclean -C $(LIB)ft_printf
	@$(MAKE) fclean -C $(LIB)libft

fclean:		clean
	@rm -rf $(NAME)

re: clean all

.PHONY:		all, clean, fclean, re
.SILENT:
