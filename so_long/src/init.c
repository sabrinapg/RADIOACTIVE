/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:50:10 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/03/13 17:53:33 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/GNL/get_next_line.h"
#include "../include/ft_printf/ft_printf.h"
#include "../include/so_long.h"

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
		ft_printf("Error\nFailed to load XPM images\n");
		return (0);
	}
	return (1);
}

static int	init_map(t_vars *vars, char **argv)
{
	vars->map = malloc(sizeof(t_map));
	if (!vars->map)
		return (0);
	vars->map->map = load_map(argv[1]);
	if (!vars->map->map)
	{
		free(vars->map);
		return (0);
	}
	if (!parse_map(vars->map->map, vars->map))
	{
		free_map(vars->map->map);
		free(vars->map);
		return (0);
	}
	return (1);
}

int	init_game(t_vars *vars, char **argv)
{
	init_vars(vars);
	if (!init_map(vars, argv))
		return (0);
	get_map_dimensions(vars->map->map, &vars->map_width, &vars->map_height);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	vars->win = mlx_new_window(vars->mlx, vars->map_width * 32,
			vars->map_height * 32, "so_long");
	if (!vars->win)
		return (0);
	if (!load_images(vars))
		return (0);
	vars->moves = 0;
	find_player_position(vars);
	vars->collectibles = count_collectibles(vars->map->map);
	return (1);
}
