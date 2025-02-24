NAME = minishell
NAME_BONUS = checker
CFLAGS = -g -Wall -Wextra -Werror
SOURCES = main.c clenup.c token_extra_functions.c token_linked_list.c \
	token_to_list.c token.c parser_add.c parser_extra.c \
	parser.c
LIB = lib/libft/libft.a
OBJ = $(SOURCES:.c=.o)

all: library $(NAME)

library:
	@cd lib/libft && $(MAKE)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -lreadline $(LIB) -o $(NAME) $(LDFLAGS)


%.o: %.c
	gcc -c $< $(CFLAGS) -Ilibft

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
