/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/25 23:28:00 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/GNL/get_next_line.h"
#include "../include/ft_printf/ft_printf.h"
#include "../include/so_long.h"

/* Load all images from XPM files */
int	load_images(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->img_wall = mlx_xpm_file_to_image(vars->mlx,
			"textures/wall.xpm", &img_width, &img_height);
	vars->img_floor = mlx_xpm_file_to_image(vars->mlx,
			"textures/floor.xpm", &img_width, &img_height);
	vars->img_player = mlx_xpm_file_to_image(vars->mlx,
			"textures/player.xpm", &img_width, &img_height);
	vars->img_collect = mlx_xpm_file_to_image(vars->mlx,
			"textures/collectible.xpm", &img_width, &img_height);
	vars->img_exit = mlx_xpm_file_to_image(vars->mlx,
			"textures/exit.xpm", &img_width, &img_height);
	if (!vars->img_wall || !vars->img_floor || !vars->img_player
		|| !vars->img_collect || !vars->img_exit)
	{
		printf("Error\nFailed to load XPM images\n");
		printf("Make sure textures/ folder exists with all .xpm files\n");
		return (0);
	}
	printf("✓ All textures loaded successfully!\n");
	printf("Wall: %p\n", vars->img_wall);
	printf("Floor: %p\n", vars->img_floor);
	printf("Player: %p\n", vars->img_player);
	return (1);
}

int	render_map(t_vars *vars)
{
    int     y;
    int     x;
    void    *img;
    char    tile;

    y = 0;
    while (y < vars->map_height)
    {
        x = 0;
        while (x < vars->map_width)
        {
            tile = vars->map->map[y][x];
            mlx_put_image_to_window(vars->mlx, vars->win,
                vars->img_floor, x * 32, y * 32);
            if (x == vars->player_x && y == vars->player_y)
                img = vars->img_player;
            else
                img = get_tile_image(vars, tile);
            if (img && tile != '0')
                mlx_put_image_to_window(vars->mlx, vars->win,
                    img, x * 32, y * 32);
            x++;
        }
        y++;
    }
 //   mlx_do_sync(vars->mlx);
    return (0);
}
			
static void	find_player_position(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			if (vars->map->map[y][x] == 'P')
			{
				vars->player_x = x;
				vars->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	count_collectibles(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	init_game(t_vars *vars, char **argv)
{
	int	i;

	i = 0;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	vars->map = malloc(sizeof(t_map));
	if (!vars->map)
		return (0);
	
	// FIXED: Pass argv[1] directly
	vars->map->map = load_map(argv[1]);
	if (!vars->map->map)
	{
		free(vars->map);
		return (0);
	}
	
	// DEBUG: Check map right after loading
	printf("\n=== DEBUG AFTER LOAD_MAP ===\n");
	while (vars->map->map[i])
	{
		printf("Row %d: [%s]\n", i, vars->map->map[i]);
		i++;
	}
	printf("Total rows: %d\n", i);
	printf("============================\n\n");
	
	if (!parse_map(vars->map->map, vars->map))
	{
  	  free_map(vars->map->map);
    	free(vars->map);
    	return (0);
	}
	printf("AFTER PARSE: w=%d h=%d\n", vars->map_width, vars->map_height);

	get_map_dimensions(vars->map->map, &vars->map_width, &vars->map_height);
	printf("w=%d h=%d\n", vars->map_width, vars->map_height);
	
	printf("BEFORE WINDOW: w=%d h=%d\n", vars->map_width, vars->map_height);
	vars->win = mlx_new_window(vars->mlx, vars->map_width * 32,
			vars->map_height * 32, "so_long");	
	printf("AFTER WINDOW: w=%d h=%d\n", vars->map_width, vars->map_height);
	if (!vars->win)
		return (0);
	if (!load_images(vars))
		return (0);
	vars->moves = 0;
	find_player_position(vars);
	vars->collectibles = count_collectibles(vars->map->map);
	printf("\n=== GAME START ===\n");
	printf("Map: %dx%d\n", vars->map_width, vars->map_height);
	printf("Player: (%d, %d)\n", vars->player_x, vars->player_y);
	printf("Collectibles: %d\n", vars->collectibles);
	printf("==================\n\n");
	printf("END OF INIT: w=%d h=%d\n", vars->map_width, vars->map_height);
	return (1);
}