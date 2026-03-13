/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:35:30 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/03/13 17:54:59 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"
#include "../include/GNL/get_next_line.h"
#include "../include/so_long.h"

void	*get_tile_image(t_vars *vars, char tile)
{
	if (tile == '1')
		return (vars->img_wall);
	else if (tile == '0')
		return (vars->img_floor);
	else if (tile == 'C')
		return (vars->img_collect);
	else if (tile == 'E')
		return (vars->img_exit);
	else if (tile == 'P')
		return (vars->img_player);
	return (vars->img_floor);
}

void	destroy_assets(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img_collect);
	mlx_destroy_image(vars->mlx, vars->img_exit);
	mlx_destroy_image(vars->mlx, vars->img_floor);
	mlx_destroy_image(vars->mlx, vars->img_player);
	mlx_destroy_image(vars->mlx, vars->img_wall);
}

int	close_window(t_vars *vars)
{
	destroy_assets(vars);
	if (vars->map)
	{
		if (vars->map->map)
			free_map(vars->map->map);
		free(vars->map);
	}
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->player_x;
	new_y = vars->player_y;
	if (keycode == ESC || keycode == K_Q)
		close_window(vars);
	if (keycode == UP || keycode == K_W)
		new_y--;
	else if (keycode == DOWN || keycode == K_S)
		new_y++;
	else if (keycode == LEFT || keycode == K_A)
		new_x--;
	else if (keycode == RIGHT || keycode == K_D)
		new_x++;
	else
		return (0);
	update_game(vars, new_x, new_y);
	return (0);
}
