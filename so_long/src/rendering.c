/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:39:34 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/03/13 15:57:55 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"
#include "../include/GNL/get_next_line.h"
#include "../include/so_long.h"

static int	can_move_to(t_vars *vars, int x, int y)
{
	char	tile;

	if (x < 0 || y < 0 || x >= vars->map_width || y >= vars->map_height)
		return (0);
	if (!(vars->map->map[y] && vars->map->map[y][x]))
		return (0);
	tile = vars->map->map[y][x];
	if (tile == '1')
		return (0);
	if (tile == 'E' && vars->collectibles > 0)
		return (0);
	return (1);
}

static void	collect_item(t_vars *vars, int x, int y)
{
	if (vars->map->map[y][x] == 'C')
	{
		vars->map->map[y][x] = '0';
		vars->collectibles--;
		ft_printf("Collected! %d remaining\n", vars->collectibles);
	}
}

static void	check_win(t_vars *vars)
{
	if (vars->map->map[vars->player_y][vars->player_x] == 'E'
		&& vars->collectibles == 0)
	{
		ft_printf("\n YOU WIN! \n");
		ft_printf("Total moves: %d\n", vars->moves);
		close_window(vars);
	}
	else if (vars->map->map[vars->player_y][vars->player_x] == 'E')
	{
		ft_printf("Collect all items first! (%d left)\n", vars->collectibles);
	}
}

void	update_game(t_vars *vars, int new_x, int new_y)
{
	if (can_move_to(vars, new_x, new_y))
	{
		vars->map->map[vars->player_y][vars->player_x] = '0';
		vars->player_x = new_x;
		vars->player_y = new_y;
		vars->moves++;
		ft_printf("Moves: %d\n", vars->moves);
		collect_item(vars, new_x, new_y);
		check_win(vars);
		render_map(vars);
	}
}
