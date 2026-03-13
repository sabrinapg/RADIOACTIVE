/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:40:18 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/03/13 17:14:40 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"
#include "../include/GNL/get_next_line.h"
#include "../include/so_long.h"

int	is_rectangular(char **map)
{
	int	i;
	int	first_len;
	int	current_len;

	if (!map || !map[0])
		return (0);
	first_len = get_line_length(map[0]);
	i = 1;
	while (map[i])
	{
		current_len = get_line_length(map[i]);
		if (current_len != first_len)
		{
			ft_printf("Error\nMap is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_counts(t_map *map_data)
{
	if (map_data->P != 1)
	{
		ft_printf("Error\nMap must have exactly 1 player (found %d)\n",
			map_data->P);
		return (0);
	}
	if (map_data->E != 1)
	{
		ft_printf("Error\nMap must have exactly 1 exit (found %d)\n",
			map_data->E);
		return (0);
	}
	if (map_data->C < 1)
	{
		ft_printf("Error\nMap must have at least 1 collectible (found %d)\n",
			map_data->C);
		return (0);
	}
	return (1);
}

int	check_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
			{
				ft_printf("Error\nInvalid character in map: '%c'\n", map[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
