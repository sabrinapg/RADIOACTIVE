/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:18:12 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/02/05 06:07:08 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*copy_line(char *line, int len)
{
	char	*result;
	int		j;

	result = malloc(len + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (j <= len)
	{
		result[j] = line[j];
		j++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	buffer_pos;
	static int	buffer_read;
	char		*line;
	char		*result;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(MAX_LINE);
	if (!line)
		return (NULL);
	i = 0;
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		line[i] = buffer[buffer_pos++];
		if (line[i++] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
	{
		free(line);
		buffer_pos = 0;
		buffer_read = 0;
		return (NULL);
	}
	result = copy_line(line, i);
	free(line);
	return (result);
}

/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/