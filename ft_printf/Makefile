CC = cc
CFLAGS = -Wextra -Werror -Wall
SRC =	print_number_printf.c\
		ft_printf.c\
		strlen_printf.c\
		putchar_printf.c\
		base_printf.c\
		pointer_printf.c\
		putstr_printf.c\
		unsigned_printf.c

NAME = libftprintf.a
HEADER = ft_printf.h
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@

re : fclean all

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJ)

.PHONY : all clean fclean re
