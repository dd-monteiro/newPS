# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/31 19:20:51 by dcarneir          #+#    #+#              #
#    Updated: 2026/06/17 00:46:31 by dcarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
	parse_numbers.c \
	init_stack.c \
	check_flags.c \
	op_push.c \
	op_rotate.c \
	op_rrotate.c \
	op_swap.c \
	select_algo.c \
	sorter_simple.c \
	utils_disorder.c \
	print_bench.c \
	sorter_medium2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re