# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 01:15:31 by dkpg-md-          #+#    #+#              #
#    Updated: 2026/02/25 03:58:54 by dkpg-md-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR	= include/LIBFT
LIBFT		= $(LIBFT_DIR)/libft.a

all: $(LIBFT) server client

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

server: server.c $(LIBFT)
	@$(CC) $(CFLAGS) server.c $(LIBFT) -o server

client: client.c $(LIBFT)
	@$(CC) $(CFLAGS) client.c $(LIBFT) -o client

bonus: $(LIBFT) server_bonus client_bonus

server_bonus: server_bonus.c $(LIBFT)
	@$(CC) $(CFLAGS) server_bonus.c $(LIBFT) -o server_bonus

client_bonus: client_bonus.c $(LIBFT)
	@$(CC) $(CFLAGS) client_bonus.c $(LIBFT) -o client_bonus

clean:
	@rm -f server.o client.o
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@rm -f server client server_bonus client_bonus
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
