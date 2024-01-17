# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:42:20 by andrefil          #+#    #+#              #
#    Updated: 2024/01/16 22:07:01 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	pipex
PRINTF		:=	ft_printf
LIBFT		:=	libft
LIBS		:=	./$(LIB_DIR)libft/libft.a ./$(LIB_DIR)ft_printf/ft_printf.a

CC			:=	cc
CFLAGS		:=	-Wextra -Wall -Werror -g3

LIB_DIR		:=	libs/
HEADERS		+=	$(addprefix $(LIB_DIR), \
				includes/ ft_printf/ \
				libft/ get_next_line/)

OBJS_DIR	:=	objs/
FILES_DIR	:=	srcs/

FILES		+=	$(addprefix $(FILES_DIR), \
				pipex.c)

OBJS		+=	$(FILES:%.c=$(OBJS_DIR)%.o)

all:		$(NAME) $(LIBFT) $(PRINTF)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)$(LIBFT)

$(PRINTF):
	@$(MAKE) -C $(LIB_DIR)$(PRINTF)

$(OBJS_DIR)%.o: %.c
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS) $(LIBS) $(HEADERS)

bonus:		$(OBJS)
	@rc rcs $(NAME) $(OBJS) $(LIBS)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) fclean -C $(LIB_DIR)$(PRINTF)
	@$(MAKE) fclean -C $(LIB_DIR)$(LIBFT)

fclean:		clean
	@rm -rf $(NAME)

re: clean all

.PHONY:		all, clean, fclean, re
.SILENT:
