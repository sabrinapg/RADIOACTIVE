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
