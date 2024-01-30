# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 15:20:31 by andrefil          #+#    #+#              #
#    Updated: 2024/01/30 18:08:58 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap

INCLUDES	:=	-I ./includes
HEADERS		:=	$(INCLUDES) -I libs/libft
LIBS		:=	./libs/libft/libft.a

CC			:=	cc
CFLAGS		:=	-Wextra -Wall -Werror -g3

FILES_DIR	:=	src/
FILES		+= $(addprefix $(FILES_DIR), \
				push_swap.c)

OBJS_DIR	:=	objs/
OBJS		+=	$(addprefix $(OBJS_DIR), $(FILES:$(FILES_DIR)%.c=%.o))

all: LIBFTX $(NAME)

LIBFTX:
	@$(MAKE) -C libs/libft

$(OBJS_DIR)%.o: $(FILES_DIR)%.C
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) clean -C libs/libft

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libs/libft

re: fclean all

.PHONY: all clean fclean
.SILENT:
