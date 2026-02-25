#include "../include/GNL/get_next_line.h"
#include "../include/so_long.h"

void	flood_fill(char **map, int start_x, int start_y, int w, int h)
{
	t_point	*stack;
	int		size;
	t_point	cur;

	stack = init_flood_stack(w, h, start_x, start_y);
	if (!stack)
		return;
	size = 1;
	while (size > 0)
	{
		cur = stack[--size];
		if (!is_valid_cell(map, cur, w, h))
			continue;
		map[cur.y][cur.x] = 'V';
		push_neighbors(stack, &size, cur, w * h);
	}
	free(stack);
}

void	push_neighbors(t_point *stack, int *size, t_point cur, int cap)
{
	if (*size + 4 >= cap)
		return;
	stack[(*size)++] = (t_point){cur.x + 1, cur.y};
	stack[(*size)++] = (t_point){cur.x - 1, cur.y};
	stack[(*size)++] = (t_point){cur.x, cur.y + 1};
	stack[(*size)++] = (t_point){cur.x, cur.y - 1};
}

t_point	*init_flood_stack(int w, int h, int start_x, int start_y)
{
	t_point	*stack;

	stack = malloc(sizeof(t_point) * (w * h));
	if (!stack)
		return (NULL);
	stack[0] = (t_point){start_x, start_y};
	return (stack);
}

int	is_unreachable(char c)
{
	if (c == 'C')
	{
		printf("Error\nNot all collectibles are reachable\n");
		return (1);
	}
	if (c == 'E')
	{
		printf("Error\nExit is not reachable\n");
		return (1);
	}
	return (0);
}

int	check_unreachable_element(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (is_unreachable(map_copy[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}