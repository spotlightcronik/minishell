NAME = minishell

CFLAGS	=	-g -Wall -Wextra -Werror
FILES	=	main.c \
			clenup.c \
			token_extra_functions.c \
			token_linked_list.c \
			token_to_list.c \
			token.c \
			parser_add.c \
			parser_extra.c \
			parser.c	\
			bi_action.c \
			bi_cd.c \
			bi_print.c \
			envp_utils.c \
			execute_builtin.c \
			execute_cmd.c \
			execute_routing.c \
			free_funcs.c \
			ft_fork.c \
			prepare_exec.c \
			signals.c

SOURCES		:=	$(addprefix src/, $(FILES))
OBJ			:=	$(addprefix obj/, $(FILES:.c=.o))

LIBFT_DIR	:=	./lib/libft
LIB = $(LIBFT_DIR)/libft.a

INCS		:=	-I ./inc \
				-I $(LIBFT_DIR)/inc

all: library  $(NAME)

obj:
	mkdir -p obj

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
