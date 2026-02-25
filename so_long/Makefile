# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 by dkpg-md-               #+#    #+#              #
#    Updated: 2026/01/28 by dkpg-md-               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = so_long

# Directories
SRC_DIR = src
INCLUDE_DIR = include
LIBFT_DIR = $(INCLUDE_DIR)/LIBFT
GNL_DIR = $(INCLUDE_DIR)/GNL
MLX_DIR = minilibx-linux
PRINTF_DIR = $(INCLUDE_DIR)/ft_printf

# Source files
SRC_FILES = main.c \
            game.c \
            game_utils.c \
            rendering.c \
            parsing.c \
            parsing_utils.c \
            valid_map.c \
            map.c \
            map_utils.c \
            free_map.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/gnl.a
MLX = $(MLX_DIR)/libmlx.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR) -I$(PRINTF_DIR)

# MLX flags for linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
NC = \033[0m

# Main rule
all: $(NAME)

# Build everything
$(NAME): $(LIBFT) $(GNL) $(PRINTF) $(MLX) $(OBJ)
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(NC)"
	@echo "$(BLUE)Run with: ./$(NAME) maps/map.ber$(NC)"

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft ready$(NC)"

$(GNL):
	@echo "$(YELLOW)Building GNL + printf...$(NC)"
	@$(MAKE) -C $(GNL_DIR)
	@echo "$(GREEN)✓ GNL + printf ready$(NC)"

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "✓ ft_printf ready"

$(MLX):
	@echo "$(YELLOW)Building MiniLibX...$(NC)"
	@$(MAKE) -C $(MLX_DIR)
	@echo "$(GREEN)✓ MiniLibX ready$(NC)"

# Compile object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$(GREEN)✓ Clean complete$(NC)"

# Full clean
fclean: clean
	@echo "$(RED)Removing $(NAME)...$(NC)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "$(GREEN)✓ Full clean complete$(NC)"

# Rebuild
re: fclean all

# Test
test: $(NAME)
	@./$(NAME) maps/map.ber

# Norminette
norm:
	@echo "$(YELLOW)Checking norm...$(NC)"
	@norminette $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h $(GNL_DIR)/*.c $(GNL_DIR)/*.h

# Help
help:
	@echo "$(GREEN)SO_LONG MAKEFILE$(NC)"
	@echo "$(YELLOW)make$(NC)       - Compile everything"
	@echo "$(YELLOW)make clean$(NC) - Remove object files"
	@echo "$(YELLOW)make fclean$(NC) - Remove all generated files"
	@echo "$(YELLOW)make re$(NC)    - Rebuild from scratch"
	@echo "$(YELLOW)make test$(NC)  - Run with test map"
	@echo "$(YELLOW)make norm$(NC)  - Check norminette"

.PHONY: all clean fclean re test norm help
