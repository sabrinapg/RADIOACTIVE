/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:34:45 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/03/13 15:40:55 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_copy_if_error(char **copy, int until)
{
	while (--until >= 0)
		free(copy[until]);
	free(copy);
}

void	free_images(t_vars *vars)
{
	if (vars->img_wall)
		mlx_destroy_image(vars->mlx, vars->img_wall);
	if (vars->img_floor)
		mlx_destroy_image(vars->mlx, vars->img_floor);
	if (vars->img_player)
		mlx_destroy_image(vars->mlx, vars->img_player);
	if (vars->img_collect)
		mlx_destroy_image(vars->mlx, vars->img_collect);
	if (vars->img_exit)
		mlx_destroy_image(vars->mlx, vars->img_exit);
}
