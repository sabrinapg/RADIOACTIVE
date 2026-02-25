#include "../include/ft_printf/ft_printf.h"
#include "../include/GNL/get_next_line.h"
#include "../include/so_long.h"

int	close_window(t_vars *vars)
{
//	free_images(vars);
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
	free_map(vars->map->map);
	free(vars->map);
	exit(0);
	return (0);
}

/* Check if player can move to position */
static int	can_move_to(t_vars *vars, int x, int y)
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
}

/* Collect item if on collectible */
static void	collect_item(t_vars *vars, int x, int y)
{
	if (vars->map->map[y][x] == 'C')
	{
		vars->map->map[y][x] = '0';
		vars->collectibles--;
		printf("Collected! %d remaining\n", vars->collectibles);
	}
}

static void	check_win(t_vars *vars)
{
	if (vars->map->map[vars->player_y][vars->player_x] == 'E'
		&& vars->collectibles == 0)
	{
		printf("\n YOU WIN! \n");
		printf("Total moves: %d\n", vars->moves);
		close_window(vars);
	}
	else if (vars->map->map[vars->player_y][vars->player_x] == 'E')
	{
		printf("Collect all items first! (%d left)\n", vars->collectibles);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->player_x;
	new_y = vars->player_y;
	
	if (keycode == ESC)
		close_window(vars);
	if (keycode == UP)
		new_y--;
	else if (keycode == DOWN)
		new_y++;
	else if (keycode == LEFT)
		new_x--;
	else if (keycode == RIGHT)
		new_x++;
	else
		return (0);
	
	if (can_move_to(vars, new_x, new_y))
	{
		vars->player_x = new_x;
		vars->player_y = new_y;
		vars->moves++;
		printf("Moves: %d\n", vars->moves);
		collect_item(vars, new_x, new_y);
		check_win(vars);
		render_map(vars);
	}
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
		printf("Line %d: [%s]\n", i, line);  // Use printf, not printf
		map[i] = line;
		strip_newline(map[i]);
		printf("Stored at map[%d] = %p\n", i, (void *)map[i]);
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
	
	printf("\n=== Verification ===\n");
	for (int j = 0; j < i; j++)
		printf("map[%d] = %p\n", j, (void *)map[j]);
	
	return (map);
}