# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 14:25:11 by andrefil          #+#    #+#              #
#    Updated: 2024/04/16 14:54:46 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	minishell

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g3
CPP_FLAGS	:=	$(addprefix -I, $(INCLUDES)) -MMD -MP

INCLUDES	:=	includes/ \
				libs/libft/

LIBS		:=	libs/libft/libft.a

OBJS_DIR	:=	objs/

SRC_FILES	+=	$(addprefix src/mandatory/, \
			   )

OBJS		:=	$(SRC_FILES:%.c=$(OBJS_DIR)%.o)

all:

LIBFT:
	@$(MAKE) -C libs/libft

$(OBJS_DIR)%.o: %.c
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPP_FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@(MAKE) clean -C libs/libft

fclean: clean
	@rm -rf $(NAME)
	@(MAKE) fclean -C libs/libft

.PHONY: all clean fclean bonus
.SILENT:


