#include "../include/ft_printf/ft_printf.h"
#include "../include/GNL/get_next_line.h"
#include "../include/so_long.h"

void destroy_assets(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img_collect);
	mlx_destroy_image(vars->mlx, vars->img_exit);
	mlx_destroy_image(vars->mlx, vars->img_floor);
	mlx_destroy_image(vars->mlx, vars->img_player);
	mlx_destroy_image(vars->mlx, vars->img_wall);
}

int	close_window(t_vars *vars)
{
//	free_images(vars);
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

/* Check if player can move to position */
/*static int	can_move_to(t_vars *vars, int x, int y)
{
	char	tile;

	if (x < 0 || x >= vars->map_width || y < 0 || y >= vars->map_height)
		return (0);
	tile = vars->map->map[y][x];
	if (tile == '1')
		return (0);
	if (tile == 'E' && vars->collectibles > 0)
		return (0);
	return (1);
}*/
static int can_move_to(t_vars *vars, int x, int y)
{
	char tile;
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

/* Collect item if on collectible */
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

void update_game(t_vars *vars, int new_x, int new_y)
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

static void	strip_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return ;
		}
		i++;
	}
}

char	**load_map(char *filename)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;
	int		capacity;

	capacity = 100;
	if (!filename)
		return (NULL);
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	
	map = malloc(sizeof(char *) * capacity);
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("Line %d: [%s]\n", i, line);  // Use ft_printf, not ft_printf
		map[i] = line;
		strip_newline(map[i]);
		ft_printf("Stored at map[%d] = %p\n", i, (void *)map[i]);
		i++;
		if (i >= capacity - 1)
			break;
	}
	map[i] = NULL;
	close(fd);
	
	if (i == 0)
	{
		free(map);
		return (NULL);
	}
	
	ft_printf("\n=== Verification ===\n");
	for (int j = 0; j < i; j++)
		ft_printf("map[%d] = %p\n", j, (void *)map[j]);
	
	return (map);
}