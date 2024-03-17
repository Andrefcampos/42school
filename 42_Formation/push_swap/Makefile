# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 15:20:31 by andrefil          #+#    #+#              #
#    Updated: 2024/03/17 16:13:58 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	push_swap

INCLUDES		:=	includes/ \
				libs/libft/

LIBS			:=	./libs/libft/libft.a
OBJS_DIR		:=	objs/

CPPFLAGS		:=	$(addprefix -I,$(INCLUDES)) -MMD -MP 
CC				:=	cc
CFLAGS			:=	-Wextra -Wall -Werror -g3

SRCS_FILES		+=	$(addprefix src/mandatory/init/, \
					push_swap.c \
					init.c \
					validate.c)

SRCS_FILES		+=	$(addprefix src/mandatory/moves/, \
					moves.c)

SRCS_FILES		+=	$(addprefix src/mandatory/clear/, \
					clear.c)

SRCS_FILES		+=	$(addprefix src/mandatory/utils/, \
				utils.c \
				utils2.c \
				utils3.c \
				utils4.c)

SRCS_FILES		+=	$(addprefix src/mandatory/sort/, \
				sort.c \
				sort2.c \
				sort_a.c \
				sort_b.c \
				stack_a.c \
				stack_b.c)

OBJS			+=	$(SRCS_FILES:%.c=$(OBJS_DIR)%.o)

all: LIBFTX $(NAME)

LIBFTX:
	@$(MAKE) -C libs/libft

$(OBJS_DIR)%.o: %.c
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) clean -C libs/libft

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libs/libft

re: fclean all

.PHONY: all clean fclean
.SILENT:
