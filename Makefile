# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcarneir <dcarneir@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/31 19:20:51 by dcarneir          #+#    #+#              #
#    Updated: 2026/06/17 18:03:00 by dcarneir         ###   ########.fr        #
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
	sorter_medium.c \
	sorter_medium_utils.c

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