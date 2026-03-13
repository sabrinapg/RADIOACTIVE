/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:17:34 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/03/13 16:45:16 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"
#include "../include/GNL/get_next_line.h"
#include "../include/so_long.h"

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
		map[i] = line;
		strip_newline(map[i]);
		i++;
		if (i >= capacity - 1)
			break ;
	}
	map[i] = NULL;
	close(fd);
	if (i == 0)
	{
		free(map);
		return (NULL);
	}
	return (map);
}
