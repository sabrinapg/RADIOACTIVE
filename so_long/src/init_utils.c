/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:50:10 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/03/13 17:48:50 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_vars(t_vars *vars)
{
	vars->collectibles = 0;
	vars->img_collect = NULL;
	vars->img_exit = NULL;
	vars->img_floor = NULL;
	vars->img_player = NULL;
	vars->img_wall = NULL;
	vars->map = NULL;
	vars->map_height = 0;
	vars->map_width = 0;
	vars->moves = 0;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->mlx = NULL;
	vars->win = NULL;
}
