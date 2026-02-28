/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:13:27 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/02/25 23:33:39 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../include/LIBFT/libft.h"
# include "../include/ft_printf/ft_printf.h"
# include "../include/GNL/get_next_line.h"

# define UP 	65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363
# define ESC	65307
# define K_Q	113
# define K_W	119
# define K_A	97
# define K_D	100
# define K_S	115

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**map;
	int		P;
	int		C;
	int		E;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		player_x;
	int		player_y;
	int		map_width;
	int		map_height;
	int		moves;
	int		collectibles;
	t_map	*map;
	void	*img_wall;        // ADD: Image pointers
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}	t_vars;

/* Graphics functions */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(t_vars *vars);
int		key_hook(int kc, t_vars *vars);

/* Map loading and parsing */
char	**load_map(char *filename);
char	*get_next_line(int fd);

// free_map
void	free_map(char **map);
void	free_copy_if_error(char **copy, int until);
void	free_images(t_vars *vars);

// game.c
int	load_images(t_vars *vars);
int	render_map(t_vars *vars);
int	init_game(t_vars *vars, char **argv);

// game_utils.c
void	*get_tile_image(t_vars *vars, char tile);

/* map.c */
void	get_map_dimensions(char **map, int *width, int *height);
int		check_walls(char **map, int width, int height);
int		count_elements(char **map, t_map *map_data);
char	**copy_map(char **map, int height);

/* valid_map.c */
int		is_rectangular(char **map);
int		validate_counts(t_map *map_data);
int		check_valid_chars(char **map);

/* map_utils.c */
int		get_line_length(char *line);
int		is_valid_char(char c);
void	init_counts(t_map *map_data);
void	count_char(char c, t_map *map_data);
int		is_valid_cell(char **map, t_point p, int width, int height);

/* parsing.c */
int		parse_map(char **map, t_map *map_data);

/* parsing_utils.c */
void	flood_fill(char **map, int start_x, int start_y, int w, int h);
void	push_neighbors(t_point *stack, int *size, t_point cur, int cap);
t_point	*init_flood_stack(int w, int h, int start_x, int start_y);
int		check_unreachable_element(char **map_copy);
int		is_unreachable(char c);

#endif
