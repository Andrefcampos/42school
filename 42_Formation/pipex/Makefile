# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 16:49:53 by andrefil          #+#    #+#              #
#    Updated: 2024/01/31 20:08:33 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	pipex
LIBFT		:=	libft
PRINTF		:=	ft_printf
LIB_DIR		:=	libs/
LIBS		:=	./$(LIB_DIR)$(LIBFT)/libft.a ./$(LIB_DIR)$(PRINTF)/ft_printf.a

CC			:=	cc
CFLAGS		:=	-Wextra -Wall -Werror -g3

HEADERS		+=	-I includes/ \
				-I $(LIB_DIR)libft/ \
				-I $(LIB_DIR)ft_printf/

OBJS_DIR	:=	objs/
FILES_DIR	:=	srcs/

FILES		+=	$(addprefix $(FILES_DIR), \
				pipex.c \
				path.c \
				proccess.c \
				error.c)

OBJS		+=	$(addprefix $(OBJS_DIR), $(FILES:$(FILES_DIR)%.c=%.o))

all: LIBFTX PRINTFX $(NAME)

LIBFTX:
	@$(MAKE) -C $(LIB_DIR)$(LIBFT)

PRINTFX:
	@$(MAKE) -C $(LIB_DIR)$(PRINTF)

$(OBJS_DIR)%.o: $(FILES_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

# bonus: LIBFTX $(OBJS)
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) clean -C $(LIB_DIR)$(LIBFT)
	@$(MAKE) clean -C $(LIB_DIR)$(PRINTF)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)$(LIBFT)
	@$(MAKE) fclean -C $(LIB_DIR)$(PRINTF)

re: fclean all

.PHONY: all bonus clean fclean re LIBFTX FT_PRINTF
.SILENT:
