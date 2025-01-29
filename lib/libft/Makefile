NAME	:=	libft.a

CC		:=	cc
CFLAGS	:=	-Wall -Werror -Wextra -g

FILES	:=	ft_atoi.c \
			ft_memcmp.c \
			ft_strdup.c \
			ft_strtrim.c \
			ft_bzero.c \
			ft_strcmp.c \
			ft_memcpy.c \
			ft_striteri.c \
			ft_substr.c \
			ft_calloc.c \
			ft_memmove.c \
			ft_strjoin.c \
			ft_tolower.c \
			ft_isalnum.c \
			ft_memset.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_isalpha.c \
			ft_putchar_fd.c \
			ft_strlcpy.c \
			ft_isascii.c \
			ft_putendl_fd.c \
			ft_strlen.c \
			ft_isdigit.c \
			ft_putnbr_fd.c \
			ft_strmapi.c \
			ft_isprint.c \
			ft_print_variadic.c \
			ft_isspace.c \
			ft_putstr_fd.c \
			ft_strncmp.c \
			ft_itoa.c \
			ft_split.c \
			ft_strnstr.c \
			ft_memchr.c \
			ft_strchr.c \
			ft_strrchr.c \
			get_next_line.c \
			ft_hextoa.c \
			ft_printf.c \
			ft_fprintf.c \
			ft_printhex.c \
			ft_printnbr.c \
			ft_printptr.c \
			ft_ptrtoa.c \
			ft_uitoa.c \
			ft_freejoin.c \
			ft_charcount.c \
			ft_highest.c \
			ft_lowest.c \
			ft_lsttoar.c \
			ft_lstinsert.c \
			ft_lstchr.c \
			ft_lstrchr.c \
			ft_pwr.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstiter.c \
			ft_lstsize.c \
			ft_lstnextsize.c \
			ft_lstprevsize.c \
			ft_lstclear.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstdetach.c \
			ft_lstfirst.c

SRCS	:=	$(addprefix src/, $(FILES))
B_SRCS	:=	$(addprefix src/, $(B_FILES))

OBJS	:=	$(addprefix obj/, $(FILES:.c=.o))
B_OBJS	:=	$(addprefix obj/, $(B_FILES:.c=.o))

INCS	:=	-I inc

all: obj ${NAME}

obj:
	@mkdir -p obj

${NAME}: ${OBJS}
	@echo "Creating: $(NAME)"
	@ar rcs ${NAME} ${OBJS}

obj/%.o: src/%.c
	@echo "Compiling: $(notdir $<)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@echo "Removing: $(NAME:.a=) object files"
	@rm -rf obj

fclean: clean
	@echo "Removing: $(NAME)"
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus obj
