/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:58:07 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/02/25 23:28:05 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/GNL/get_next_line.h"
#include "../include/so_long.h"

void	get_map_dimensions(char **map, int *width, int *height)
{
	int	i;
	int	len;

	*height = 0;
	*width = 0;
	i = 0;
	while (map[i])
	{
		len = 0;
		while (map[i][len] && map[i][len] != '\n')
			len++;
		if (len > *width)
			*width = len;
		(*height)++;
		i++;
	}
}

int	check_walls(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				if (map[i][j] != '1')
				{
					ft_printf("Error\nMap not surrounded by walls\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	count_elements(char **map, t_map *map_data)
{
	int	i;
	int	j;

	init_counts(map_data);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			count_char(map[i][j], map_data);
			j++;
		}
		i++;
	}
	return (validate_counts(map_data));
}

static char	*copy_line(char *line)
{
	char	*copy;
	int		j;

	j = 0;
	while (line[j])
		j++;
	copy = malloc(sizeof(char) * (j + 1));
	if (!copy)
		return (NULL);
	j = 0;
	while (line[j])
	{
		copy[j] = line[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

// create a copy of the map for flood fill
char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = copy_line(map[i]);
		if (!copy[i])
		{
			free_copy_if_error(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}