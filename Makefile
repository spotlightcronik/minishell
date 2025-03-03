NAME = minishell

CFLAGS	=	-g -Wall -Wextra -Werror
FILES	=	hardcode_parse.c \
			execution/bi_exit.c \
			execution/bi_unset.c \
			execution/bi_export.c \
			execution/bi_cd.c \
			execution/bi_pwd.c \
			execution/bi_env.c \
			execution/bi_echo.c \
			execution/envp_utils.c \
			execution/execute_builtin.c \
			execution/execute_cmd.c \
			execution/execute_line.c \
			execution/free_funcs.c \
			execution/ft_fork.c \
			execution/execute_redirs.c \
			execution/ft_dup2.c \
			execution/get_cmd_path.c \
			execution/heredoc_manager.c

SOURCES		:=	$(addprefix src/, $(FILES))
OBJ			:=	$(addprefix obj/, $(FILES:.c=.o))

LIBFT_DIR	:=	./lib/libft
LIB = $(LIBFT_DIR)/libft.a

INCS		:=	-I ./inc \
				-I $(LIBFT_DIR)/inc

all: library  $(NAME)

obj:
	mkdir -p obj/execution

library:
	@cd lib/libft && $(MAKE)

$(NAME): obj $(OBJ)
	cc $(CFLAGS) $(OBJ) -lreadline $(LIB) -o $(NAME) $(LDFLAGS)


obj/%.o: src/%.c
	gcc $(INCS) -c $< $(CFLAGS) -Ilibft -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	$(MAKE) -C lib/libft clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(LIB)
	$(MAKE) -C lib/libft fclean

re: fclean all

.PHONY: all library clean fclean re
