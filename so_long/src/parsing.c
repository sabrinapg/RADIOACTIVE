#include "../include/GNL/get_next_line.h"
#include "../include/so_long.h"

// find player position
static void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return;
			}
			j++;
		}
		i++;
	}
}

static int	validate_path(char **map, int width, int height)
{
	char	**map_copy;
	int		player_x;
	int		player_y;
	int		has_error;

	map_copy = copy_map(map, height);
	if (!map_copy)
	{
		ft_printf("Error\nMemory allocation failed\n");
		return (0);
	}
	find_player(map_copy, &player_x, &player_y);
	flood_fill(map_copy, player_x, player_y, width, height);
	has_error = check_unreachable_element(map_copy);
	free_map(map_copy);
	return (!has_error);
}

static int	validate_basic_checks(char **map)
{
	if (!map || !map[0])
	{
		ft_printf("Error\nEmpty map\n");
		return (0);
	}
	if (!check_valid_chars(map))
		return (0);
	if (!is_rectangular(map))
		return (0);
	return (1);
}

static int	validate_dimensions(int width, int height)
{
	if (width < 3 || height < 3)
	{
		ft_printf("Error\nMap too small (minimum 3x3)\n");
		return (0);
	}
	return (1);
}

int	parse_map(char **map, t_map *map_data)
{
	int	width;
	int	height;

	if (!validate_basic_checks(map))
		return (0);
	get_map_dimensions(map, &width, &height);
	if (!validate_dimensions(width, height))
		return (0);
	if (!check_walls(map, width, height))
		return (0);
	if (!count_elements(map, map_data))
		return (0);
	if (!validate_path(map, width, height))
		return (0);
	ft_printf("BEFORE map_data->map: P=%d E=%d C=%d\n", map_data->P, map_data->E, map_data->C);
	ft_printf("map_data=%p &map_data->map=%p\n", (void*)map_data, (void*)&map_data->map);
	map_data->map = map;
	ft_printf("AFTER map_data->map: P=%d E=%d C=%d\n", map_data->P, map_data->E, map_data->C);
//	ft_printf("Map validation successful!\n");
	return (1);
}