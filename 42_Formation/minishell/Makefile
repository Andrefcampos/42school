# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 14:25:11 by andrefil          #+#    #+#              #
#    Updated: 2024/05/03 00:36:52 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	minishell

INCLUDES	:=	includes/ \
				libs/libft/

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g3
CPP_FLAGS	:=	$(addprefix -I, $(INCLUDES)) -MMD -MP

LIBS		:=	libs/libft/libft.a -lreadline

OBJS_DIR	:=	objs/

SRC_FILES	+=	$(addprefix src/mandatory/init/, \
				main.c)

SRC_FILES	+=	$(addprefix src/mandatory/builtins/, \
				dir.c)

SRC_FILES	+=	$(addprefix src/mandatory/env_vars/, \
				env_vars.c)

SRC_FILES	+=	$(addprefix src/mandatory/error/, \
				close_free.c)

SRC_FILES	+=	$(addprefix src/mandatory/abstract_syntax_tree/, \
				ast_constructor.c \
				ast_utils.c \
				ast_utils2.c)

SRC_FILES	+=	$(addprefix src/mandatory/tokenizer/, \
				token_constructor.c \
				token_utils.c)

SRC_FILES	+=	$(addprefix src/mandatory/execution/, \
				begin_executing.c \
				execute_command.c \
				execute_here_doc.c \
				execute_pipe.c \
				execute_redirect.c)

SRC_FILES	+=	$(addprefix src/mandatory/parser/, \
				syntax_checker.c \
				syntax_checker_utils.c)

SRC_FILES	+=	$(addprefix src/mandatory/utils/, \
				node.c \
				print.c)

OBJS		:=	$(SRC_FILES:%.c=$(OBJS_DIR)%.o)

all: LIBFT $(NAME)

LIBFT:
	@$(MAKE) -C libs/libft

$(OBJS_DIR)%.o: %.c
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPP_FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) clean -C libs/libft

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C libs/libft

re: fclean all

.PHONY: all clean fclean bonus
.SILENT:
