#include "../include/so_long.h"

int	get_line_length(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len);
}

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C' || c == '\n')
		return (1);
	return (0);
}

void	init_counts(t_map *map_data)
{
	map_data->P = 0;
	map_data->E = 0;
	map_data->C = 0;
}

void	count_char(char c, t_map *map_data)
{
	if (c == 'P')
		map_data->P++;
	else if (c == 'E')
		map_data->E++;
	else if (c == 'C')
		map_data->C++;
}

int	is_valid_cell(char **map, t_point p, int width, int height)
{
	if (p.x < 0 || p.y < 0 || p.x >= width || p.y >= height)
		return (0);
	if (map[p.y][p.x] == '1' || map[p.y][p.x] == 'V')
		return (0);
	return (1);
}
