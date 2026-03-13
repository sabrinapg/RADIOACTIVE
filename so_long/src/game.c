/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/03/13 15:48:35 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/GNL/get_next_line.h"
#include "../include/ft_printf/ft_printf.h"
#include "../include/so_long.h"

void	put_proper_tile(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, 
		vars->img_floor, x * 32, y * 32);
	if (vars->map->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, 
			vars->win, vars->img_wall, x * 32, y * 32);
	else if (vars->map->map[y][x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_exit, 
			x * 32, y * 32);
	else if (vars->map->map[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_collect, 
			x * 32, y * 32);
}

void	put_player(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img_player, vars->player_x * 32, vars->player_y * 32);
}

int	render_map(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			put_proper_tile(vars, x, y);
			x++;
		}
		y++;
	}
	put_player(vars);
	return (0);
}
