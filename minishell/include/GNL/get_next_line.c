/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:18:12 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/03/13 18:58:03 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract(const char *bffr)
{
	int		i;
	char	*sentence;

	i = 0;
	if (!bffr || !bffr[0])
		return (NULL);
	while (bffr[i] && bffr[i] != '\n')
		i++;
	if (bffr[i] == '\n')
		i++;
	sentence = malloc((sizeof(char) * (i + 1)));
	if (!sentence)
		return (NULL);
	i = 0;
	while (bffr[i] && bffr[i] != '\n')
	{
		sentence[i] = bffr[i];
		i++;
	}
	if (bffr[i] == '\n')
		sentence[i++] = '\n';
	sentence[i] = '\0';
	return (sentence);
}

char	*ft_connect(char *gnlbffr, char *read_buffer)
{
	char	*tmp;

	tmp = ft_strjoin(gnlbffr, read_buffer);
	free(gnlbffr);
	return (tmp);
}

static char	*ft_remainder(char *bffr)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	if (!bffr)
		return (NULL);
	while (bffr[i] && bffr[i] != '\n')
		i++;
	if (!bffr[i])
		return (free(bffr), NULL);
	leftover = malloc(sizeof(char) * (ft_strlen(bffr) - i + 1));
	if (!leftover)
		return (free(bffr), NULL);
	i++;
	j = 0;
	while (bffr[i])
		leftover[j++] = bffr[i++];
	leftover[j] = '\0';
	free(bffr);
	return (leftover);
}

static char	*read_file(char *gnlbffr, int fd)
{
	int		byrd;
	char	*bffr;

	bffr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (bffr == NULL)
		return (NULL);
	byrd = 1;
	while (!ft_strchr(gnlbffr, '\n') && byrd > 0)
	{
		byrd = read(fd, bffr, BUFFER_SIZE);
		if (byrd < 0)
			return (free(bffr), free(gnlbffr), NULL);
		bffr[byrd] = '\0';
		gnlbffr = ft_connect(gnlbffr, bffr);
	}
	free(bffr);
	return (gnlbffr);
}

char	*get_next_line(int fd)
{
	static char	*bffr;
	char		*dst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!bffr)
		bffr = ft_calloc(1, sizeof(char));
	if (!bffr)
		return (NULL);
	bffr = read_file(bffr, fd);
	if (!bffr || bffr[0] == '\0')
	{
		free(bffr);
		bffr = NULL;
		return (bffr);
	}
	dst = extract(bffr);
	bffr = ft_remainder(bffr);
	return (dst);
}

/*
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <test.txt>\n", argv[0]);
        return (1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    char *line;
    while((line = get_next_line(fd)) != NULL)
    {
	printf("%s\n", line);
	free(line);
    }
    close(fd);
    return (0);
}
*/
