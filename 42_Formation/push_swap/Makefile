# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 15:20:31 by andrefil          #+#    #+#              #
#    Updated: 2024/03/15 10:47:44 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap

INCLUDES	:=	includes/ \
				libs/libft/
CPPFLAGS	:=	$(addprefix -I,$(INCLUDES)) -MMD -MP 
LIBS		:=	./libs/libft/libft.a

CC			:=	cc
CFLAGS		:=	-Wextra -Wall -Werror -g3

FILES_DIR	:=	src/
FILES		+= $(addprefix $(FILES_DIR), \
				push_swap.c \
				init.c \
				clear.c \
				utils.c \
				utils2.c \
				utils3.c \
				utils4.c \
				moves.c \
				sort.c \
				sort2.c \
				sort_a.c \
				sort_b.c \
				stack_a.c \
				stack_b.c \
				validate.c)

OBJS_DIR	:=	objs/
OBJS		+=	$(addprefix $(OBJS_DIR), $(FILES:$(FILES_DIR)%.c=%.o))

all: LIBFTX $(NAME)

LIBFTX:
	@$(MAKE) -C libs/libft

$(OBJS_DIR)%.o: $(FILES_DIR)%.c
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
