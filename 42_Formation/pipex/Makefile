# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:42:20 by andrefil          #+#    #+#              #
#    Updated: 2024/01/17 15:16:46 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	pipex
PRINTF		:=	ft_printf
LIBFT		:=	libft
LIBS		:=	./$(LIB_DIR)libft/libft.a ./$(LIB_DIR)ft_printf/ft_printf.a

CC			:=	cc
CFLAGS		:=	-Wextra -Wall -Werror -g3

LIB_DIR		:=	libs/
HEADERS		+=	includes/ $(addprefix $(LIB_DIR), \
				ft_printf/ \
				libft/ get_next_line/)

OBJS_DIR	:=	objs/
FILES_DIR	:=	srcs/

FILES		+=	$(addprefix $(FILES_DIR), \
				pipex.c)

OBJS		+=	$(FILES:$(OBJS_DIR)%.c=%.o)

all:		$(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)$(LIBFT)

$(PRINTF):
	@$(MAKE) -C $(LIB_DIR)$(PRINTF)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT) $(PRINTF)
	@ar rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

bonus:		$(OBJS) $(LIBFT) $(PRINTF)
	@ar rcs $(NAME) $(OBJS) $(LIBS)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) fclean -C $(LIB_DIR)$(PRINTF)
	@$(MAKE) fclean -C $(LIB_DIR)$(LIBFT)

fclean:		clean
	@rm -rf $(NAME)

re: clean all

.PHONY:		all, clean, fclean, re
