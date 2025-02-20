NAME		:=	minishell_execution

CC			:=	cc
CFLAGS		:=	-g -Wall -Werror -Wextra

FILES		:=	bi_action.c \
				bi_cd.c \
				bi_print.c \
				envp_utils.c \
				execute_builtin.c \
				execute_cmd.c \
				execute_routing.c \
				execution_parser.c \
				free_funcs.c \
				ft_fork.c \
				prepare_exec.c \

SRCS		:=	$(addprefix src/, $(FILES))
OBJS		:=	$(addprefix obj/, $(FILES:.c=.o))

LIBFT_DIR	:=	./lib/libft
LIBFT		:=	$(LIBFT_DIR)/libft.a

LIBS		:= $(LIBFT)

INCS		:=	-I ./inc \
				-I $(LIBFT_DIR)/inc

all: $(NAME)

$(NAME): $(LIBFT)  obj $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
	make -sC $(LIBFT_DIR)

obj:
	mkdir -p obj

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf obj
	make -sC $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
