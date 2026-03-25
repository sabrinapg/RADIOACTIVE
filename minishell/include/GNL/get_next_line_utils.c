/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:17:52 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/10/21 17:32:59 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			mx;
	size_t			i;
	void			*bx;
	unsigned char	*byte_bx;

	i = 0;
	if (nmemb != 0 && size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	mx = nmemb * size;
	bx = malloc(mx);
	if (!bx)
		return (NULL);
	byte_bx = (unsigned char *)bx;
	while (i < mx)
	{
		byte_bx[i] = 0;
		i++;
	}
	return (bx);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*result;
	t_values	vals;

	if (!s1 || !s2)
		return (NULL);
	vals.y = ft_strlen(s1);
	vals.z = ft_strlen(s2);
	result = malloc(sizeof(char) * (vals.y + vals.z + 1));
	if (!result)
		return (NULL);
	vals.i = 0;
	while (vals.i < vals.y)
	{
		result[vals.i] = s1[vals.i];
		vals.i++;
	}
	vals.j = 0;
	while (vals.j < vals.z)
	{
		result[vals.i + vals.j] = s2[vals.j];
		vals.j++;
	}
	result[vals.i + vals.j] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
