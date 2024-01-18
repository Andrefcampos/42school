# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:42:20 by andrefil          #+#    #+#              #
#    Updated: 2024/01/17 21:32:32 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	pipex
PRINTF		:=	ft_printf
LIBFT		:=	libft
LIB_DIR		:=	libs/
LIBS		:=	./$(LIB_DIR)$(LIBFT)/libft.a ./$(LIB_DIR)$(PRINTF)/ft_printf.a

CC			:=	cc
CFLAGS		:=	-Wextra -Wall -Werror -g3


HEADERS		+=	-I includes/ \
				-I $(LIB_DIR)ft_printf/ \
				-I $(LIB_DIR)libft/ \
				-I $(LIB_DIR)get_next_line/

OBJS_DIR	:=	objs/
FILES_DIR	:=	srcs/

FILES		+=	$(addprefix $(FILES_DIR), \
				pipex.c \
				error.c)

OBJS		+=	$(FILES:$(OBJS_DIR)%.c=%.o)

all:		$(NAME)

LIBFTX:
	@$(MAKE) -C $(LIB_DIR)$(LIBFT)

PRINTFX:
	@$(MAKE) -C $(LIB_DIR)$(PRINTF)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME):	LIBFTX PRINTFX $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(HEADERS) $(OBJS) $(LIBS)

bonus:		$(LIBFT) $(PRINTF) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(LIBS)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) fclean -C $(LIB_DIR)$(PRINTF)
	@$(MAKE) fclean -C $(LIB_DIR)$(LIBFT)

fclean:		clean
	@rm -rf $(NAME)

re: clean all

.PHONY:		all, clean, fclean, re
.SILENT:
