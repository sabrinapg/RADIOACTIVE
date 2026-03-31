# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/28 20:12:59 by dkpg-md-          #+#    #+#              #
#    Updated: 2026/03/28 21:15:41 by dkpg-md-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

TKN_DIR = tokens
INCLUDE_DIR = include
LIBFT_DIR = $(INCLUDE_DIR)/LIBFT
GNL_DIR = $(INCLUDE_DIR)/GNL
PRINTF_DIR = $(INCLUDE_DIR)/ft_printf

#need to account different dir and main
TKN_FILES = ft_strtok.c

# might need to change this with parse, exec, etc.
SRC = $(addprefix $(TKN_DIR)/, $(TKN_FILES))
OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/gnl.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
NC = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(PRINTF) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) $(PRINTF) -o $(NAME)
	@echo "$(GREEN) $(NAME) created successfully"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN) libft ready$(NC)"

$(GNL):
	@$(MAKE) -C $(GNL_DIR)
	@echo "$(GREEN) GNL ready$(NC)"

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "$(GREEN) printf ready$(NC)"

# compile obj files for token folder
$(TKN_DIR)/%.o: $(TKN_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$(GREEN) Clean complete$(NC)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "$(GREEN) Full clean complete$(NC)"

re: fclean all

#check this -- incomplete
norm:
	@echo "$(YELLOW)Checking norm...$(NC)"
	@norminette $(TKN_DIR)/*.c $(INCLUDE_DIR)/*.h $(GNL_DIR)/*.c

.PHONY: all clean fclean re norm
