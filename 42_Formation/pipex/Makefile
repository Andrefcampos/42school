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
				path.c \
				process.c \
				error.c)

OBJS		+=	$(addprefix $(OBJS_DIR), $(FILES:$(FILES_DIR)%.c=%.o))

all: $(NAME)

LIBFTX:
	@$(MAKE) -C $(LIB_DIR)$(LIBFT)

PRINTFX:
	@$(MAKE) -C $(LIB_DIR)$(PRINTF)

$(OBJS_DIR)%.o: $(FILES_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): LIBFTX PRINTFX $(OBJS)
	ar rcs $(NAME) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

bonus: LIBFTX PRINTFX $(OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBS)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) clean -C $(LIB_DIR)$(PRINTF)
	@$(MAKE) clean -C $(LIB_DIR)$(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)$(PRINTF)
	@$(MAKE) fclean -C $(LIB_DIR)$(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re LIBFTX PRINTFX
