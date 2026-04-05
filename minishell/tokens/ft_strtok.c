/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:30:36 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/03/18 15:30:37 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

static int	count_tokens(const char *s, const char *c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != *c && (i == 0 || s[i - 1] == *c))
			count++;
		i++;
	}
	return (count);
}

static void	free_tokens(char **tokens, int idx)
{
	int	k;

	k = 0;
	while (k < idx)
	{
		free(tokens[k]);
		k++;
	}
	free(tokens);
}

static char	**fill_tokens(char **tokens, const char *s, const char *c)
{
	int	start;
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (s[i])
	{
		while (s[i] == *c)
			i++;
		if (s[i] && s[i] != *c)
		{
			start = i;
			while (s[i] && s[i] != *c)
				i++;
			tokens[idx] = ft_substr(s, start, i - start);
			if (!tokens[idx])
				return (free_tokens(tokens, idx), NULL);
			idx++;
		}
	}
	return (tokens[idx] = NULL, tokens); 
}

char	**ft_strtok(const char *s, const char *c)
{
	char	**tokens;
	int		word;

	if (!s)
		return (NULL);
	word = count_tokens(s, c);
	tokens = malloc(sizeof(char *) * (word + 1));
	if (!tokens)
		return (NULL);
	return (fill_tokens(tokens, s, c));
}
