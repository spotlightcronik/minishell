NAME		:=	minishell_execution

CC			:=	cc
CFLAGS		:=	-g -Wall -Werror -Wextra

FILES		:=	execute_line.c \
				execution_parser.c \
				free_funcs.c \
				prepare_exec.c

LIBFT_DIR	:=	./lib/libft
LIBFT		:=	$(LIBFT_DIR)/libft.a

LIBS		:= $(LIBFT)

SRCS		:=	$(addprefix src/, $(FILES))
OBJS		:=	$(addprefix obj/, $(FILES:.c=.o))

INCS		:=	-I ./inc \
				-I $(LIBFT_DIR)/inc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
	make -sC $(LIBFT_DIR)

obj:
	mkdir -p obj

obj/%.o: src/%.c obj
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf obj
	make -sC $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all obj clean fclean re
