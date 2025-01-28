NAME = minishell
CFLAGS = -g -Wall -Wextra -Werror
SOURCES = main.c
HEDER = pars.h
OBJ = $(SOURCES:.c=.o)
OBJ_BONUS = $(SOURCES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEDER)
	cc $(CFLAGS) $(OBJ) -lreadline -o $(NAME)


%.o: %.c
	gcc -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all library clean fclean re
