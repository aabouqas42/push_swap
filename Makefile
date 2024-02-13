# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 01:53:50 by aabouqas          #+#    #+#              #
#    Updated: 2024/02/13 08:56:15 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Werror -Wall

SRC =	push_swap_mandatory/stack_manager.c\
		push_swap_mandatory/push_swap_utils.c\
		push_swap_mandatory/memory_manager.c\
		push_swap_mandatory/input_checker.c\
		push_swap_mandatory/instractions/part1.c\
		push_swap_mandatory/instractions/part2.c\
		push_swap_mandatory/instractions/part3.c\
		push_swap_mandatory/get_data.c\
		push_swap_mandatory/stack_utils.c\
		push_swap_mandatory/sorter.c\
		push_swap_mandatory/to_b_to_a.c

LIBFT_SRC =	libft/ft_atoi.c\
			libft/ft_memcmp.c\
			libft/ft_strjoin.c\
			libft/ft_bzero.c\
			libft/ft_memcpy.c\
			libft/ft_strlcat.c\
			libft/ft_calloc.c\
			libft/ft_memmove.c\
			libft/ft_strlcpy.c\
			libft/ft_isalnum.c\
			libft/ft_memset.c\
			libft/ft_strlen.c\
			libft/ft_isalpha.c\
			libft/ft_putchar_fd.c\
			libft/ft_strmapi.c\
			libft/ft_isascii.c\
			libft/ft_putendl_fd.c\
			libft/ft_strncmp.c\
			libft/ft_isdigit.c\
			libft/ft_putnbr_fd.c\
			libft/ft_strnstr.c\
			libft/ft_isprint.c\
			libft/ft_putstr_fd.c\
			libft/ft_strrchr.c\
			libft/ft_itoa.c\
			libft/ft_split.c\
			libft/ft_strtrim.c\
			libft/ft_strchr.c\
			libft/ft_substr.c\
			libft/ft_strdup.c\
			libft/ft_tolower.c\
			libft/ft_memchr.c\
			libft/ft_striteri.c\
			libft/ft_toupper.c

PRINTF_SRC =	ft_printf/print_number_printf.c\
				ft_printf/ft_printf.c\
				ft_printf/strlen_printf.c\
				ft_printf/putchar_printf.c\
				ft_printf/base_printf.c\
				ft_printf/pointer_printf.c\
				ft_printf/putstr_printf.c\
				ft_printf/unsigned_printf.c

BONUS_SRC =	push_swap_bonus/input_checker_bonus.c\
			push_swap_bonus/memory_manager_bonus.c\
			push_swap_bonus/push_swap_utils_bonus.c\
			push_swap_bonus/stack_manager_bonus.c\
			push_swap_bonus/stack_utils_bonus.c\
			push_swap_bonus/instructions_manager_bonus.c\
			push_swap_bonus/instractions/part1_bonus.c\
			push_swap_bonus/instractions/part2_bonus.c\
			push_swap_bonus/instractions/part3_bonus.c\
			push_swap_bonus/get_next_line/get_next_line.c\
			push_swap_bonus/get_next_line/get_next_line_utils.c

MAIN = push_swap.c
MAIN_OBJ = push_swap.o
MAIN_BONUS = push_swap_bonus.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
HEADER = push_swap_mandatory/push_swap.h

BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_MAIN = push_swap_bonus.c 
BONUS_MAIN_OBJ = push_swap_bonus.o
BONUS = checker
BONUS_HEADER = push_swap_bonus/push_swap_bonus.h

all: $(NAME) $(LIBFT) $(PRINTF)

$(NAME): $(LIBFT) $(PRINTF) $(HEADER) $(OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

bonus: $(BONUS) $(LIBFT) $(PRINTF)


$(BONUS): $(BONUS_HEADER) $(LIBFT) $(PRINTF) $(BONUS_OBJ) $(BONUS_MAIN_OBJ)
	$(CC) $(CFLAGS) $(BONUS_MAIN_OBJ) $(BONUS_OBJ) $(LIBFT) $(PRINTF) -o $(BONUS)

push_swap_bonus.o: push_swap_bonus.c
	$(CC) $(CFLAGS) -c push_swap_bonus.c
push_swap_bonus/%.o: push_swap_bonus/%.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


push_swap.o: $(MAIN) $(HEADER)
	$(CC) $(CFLAGS) -c $(MAIN)
push_swap_mandatory/%.o: push_swap_mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): libft/libft.h $(LIBFT_SRC)
	make -C libft
	
$(PRINTF): ft_printf/ft_printf.h $(PRINTF_SRC)
	make -C ft_printf

re: fclean all

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)
	rm -rf $(BONUS)
	rm -rf $(PRINTF)
	rm -rf $(MAIN_OBJ)
	rm -rf $(BONUS_MAIN_OBJ)
	

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJ)
	rm -rf $(BONUS_OBJ)
	
.PHONY: clean