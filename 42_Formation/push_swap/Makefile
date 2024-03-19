# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 15:20:31 by andrefil          #+#    #+#              #
#    Updated: 2024/03/19 12:26:13 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	push_swap
NAME_BONUS			:=	checker

INCLUDES			:=	includes/ \
						libs/libft/

INCLUDES_BONUS		:=	includes/ \
						libs/libft/

LIBS				:=	libs/libft/libft.a
OBJS_DIR			:=	objs/
OBJS_BONUS_DIR		:=	objs_bonus/

CPPFLAGS			:=	$(addprefix -I,$(INCLUDES)) -MMD -MP 
CPPFLAGS_BONUS		:=	$(addprefix -I,$(INCLUDES_BONUS)) -MMD -MP 
CC					:=	cc
CFLAGS				:=	-Wextra -Wall -Werror -g3

SRCS_FILES			+=	$(addprefix src/mandatory/init/, \
						push_swap.c \
						init.c \
						validate.c)

SRCS_FILES			+=	$(addprefix src/mandatory/moves/, \
						moves.c)

SRCS_FILES			+=	$(addprefix src/mandatory/clear/, \
						clear.c)

SRCS_FILES			+=	$(addprefix src/mandatory/utils/, \
						utils.c \
						utils2.c \
						utils3.c \
						utils4.c)

SRCS_FILES			+=	$(addprefix src/mandatory/sort/, \
						sort.c \
						sort2.c \
						sort_a.c \
						sort_b.c \
						stack_a.c \
						stack_b.c)

SRCS_FILES_BONUS	+=	$(addprefix src/bonus/init/, \
						checker.c \
						validate.c)
							
SRCS_FILES_BONUS	+= $(addprefix src/bonus/moves/, \
						moves.c)

SRCS_FILES_BONUS	+= $(addprefix src/bonus/utils/, \
						utils.c \
						utils2.c)

SRCS_FILES_BONUS	+= $(addprefix src/bonus/clear/, \
						clear.c)

OBJS_BONUS			+=	$(SRCS_FILES_BONUS:%.c=$(OBJS_BONUS_DIR)%.o)
OBJS				+=	$(SRCS_FILES:%.c=$(OBJS_DIR)%.o)

all: LIBFTX $(NAME)

bonus: LIBFTX $(NAME_BONUS)

LIBFTX:
	@$(MAKE) -C libs/libft

$(OBJS_DIR)%.o: %.c
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJS_BONUS_DIR)%.o: %.c
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS_BONUS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) -o $(NAME_BONUS)

clean:
	@rm -rf $(OBJS_DIR) $(OBJS_BONUS_DIR)
	@$(MAKE) clean -C libs/libft

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) fclean -C libs/libft

re: fclean all

.PHONY: all clean fclean bonus
.SILENT:
