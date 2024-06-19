# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 15:00:37 by andrefil          #+#    #+#              #
#    Updated: 2024/06/19 01:46:20 by andrefil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	philo

CC			:=	cc

# ------------------ INCLUDE ------------------ #
LIBS		:=	-pthread
INCLUDES	:=	includes/

# ------------------- FLAGS ------------------- #
CFLAGS		:=	-Wall -Werror -Wextra -g3
CP_FLAGS	:=	$(addprefix -I, $(INCLUDES)) -MMD -MP

# ------------------- FILES ------------------- #
SRC_FILES	+=	$(addprefix src/mandatory/init/, \
					main.c \
					init.c \
					threads.c)

SRC_FILES	+=	$(addprefix src/mandatory/actions/, \
					actions.c \
					eat.c \
					sleep.c \
					think.c \
					die.c)


SRC_FILES	+=	$(addprefix src/mandatory/validations/, \
				validation_args.c)

SRC_FILES	+=	$(addprefix src/mandatory/utils/, \
					utils.c \
					time.c \
					print.c)

# -------------------- OBJ -------------------- #
OBJS_DIR	:=	src/objs/
OBJS		:=	$(SRC_FILES:%.c=$(OBJS_DIR)%.o)

# ----------------- DEFINES ------------------ #

define CHECK_OBJS
    @if [ -d $(OBJS_DIR) ]; then \
        if [ `find $(OBJS_DIR) -name "*.o" -print | wc -l` -eq `echo $(OBJS) | wc -w` ]; then \
            echo "\033[0;33mObjects already exist and are up to date\033[0m"; \
        else \
            $(MAKE) compile_objs; \
        fi \
    else \
        $(MAKE) compile_objs; \
    fi
endef

define COMPILE_OBJS
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CP_FLAGS) -o $@ -c $<
endef

define CLEAN_OBJS
    @if [ -d $(OBJS_DIR) ]; then \
        if find $(OBJS_DIR) -name "*.o" -print -quit | grep -q .; then \
            rm -rf $(OBJS_DIR); \
            echo "\033[0;34mObjects clean\033[0m"; \
        else \
            echo "\033[0;33mNo objects to clean\033[0m"; \
        fi \
    else \
        echo "\033[0;33mNo objects to clean\033[0m"; \
    fi
endef

define FCLEAN_BIN
	@if [ -f $(NAME) ]; then \
		rm -rf $(NAME); \
		echo "\033[0;34mBinary clean\033[0m"; \
	else \
		echo "\033[0;33mNo binary to clean\033[0m"; \
	fi
endef

# define COMPILE_AND_DISPLAY_PROGRESS
#     @count=0; \
#     total=$(words $(OBJS)); \
#     for src in $(SRC_FILES); do \
#         obj=$(src:%.c=$(OBJS_DIR)%.o); \
#         $(MAKE) --no-print-directory $$obj; \
#         count=$$((count + 1)); \
#         percent=$$((100 * count / total)); \
#         printf "\rCompiling... [%d%%]" $$percent; \
# 		sleep 0.5; \
#     done; \
#     echo "\rCompiling... [100%%]"
# endef

# ------------------ COMPILE ------------------ #
all: $(NAME)

compile_objs:
	$(COMPILE_AND_DISPLAY_PROGRESS)

$(OBJS_DIR)%.o: %.c
	$(COMPILE_OBJS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME); \
	echo "\033[0;32mPhilo compiled\033[0m"; \

clean:
	$(CLEAN_OBJS)

fclean: clean
	$(FCLEAN_BIN)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
