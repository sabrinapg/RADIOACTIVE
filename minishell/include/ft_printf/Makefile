# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 19:47:21 by dkpg-md-          #+#    #+#              #
#    Updated: 2025/06/26 20:35:52 by dkpg-md-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = libft.c ft_printf.c ft_int.c ft_ptr.c ft_str.c ft_hex.c 

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
