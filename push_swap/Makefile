# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 03:10:01 by dkpg-md-          #+#    #+#              #
#    Updated: 2026/02/25 03:10:03 by dkpg-md-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = main.c stack.c utils.c utils2.c op1.c op2.c op3.c op4.c \
        input_chk.c init.c sort_tiny.c position.c calculation.c \
        move.c sort.c
BONUS_SRCS = checker_bonus.c stack.c utils.c utils2.c op1.c op2.c op3.c op4.c \
        input_chk.c init.c sort_tiny.c position.c calculation.c \
        move.c sort.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
