# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: username <username@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 20:30:00 by username           #+#    #+#              #
#    Updated: 2025/03/24 20:30:00 by username          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
SRCS        = push_swap.c push_swap.utils.c operations.c small.c quicksort.c turksort.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) push_swap.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
