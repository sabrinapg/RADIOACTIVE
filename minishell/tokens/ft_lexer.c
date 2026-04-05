/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:31:43 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/04/05 17:32:25 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "token.h"

static int	is_special(char c)
{
	return (c == ' ' || c == '|' || c == '<' || c == '>');
}

static t_token	*get_word(const char *s, int *i)
{
	int		start;

	start = *i;
	while (s[*i] && !is_special(s[*i]))
		(*i)++;
	return (ft_new_word(s, start, *i - start));
}

static void	add_token(t_token **head, t_token **cur, t_token *tok)
{
	if (!*head)
		*head = tok;
	else
		(*cur)->next = tok;
	*cur = tok;
}

t_token	*ft_lexer(const char *s)
{
	t_token	*head;
	t_token	*cur;
	t_token	*tok;
	int		i;

	head = NULL;
	cur = NULL;
	i = 0;
	while (s[i])
	{
		tok = NULL;
		if (s[i] == ' ')
			i++;
		else if (s[i] == '|' || s[i] == '<' || s[i] == '>')
			tok = ft_get_operator(s, &i);
		else
			tok = get_word(s, &i);
		if (tok)
			add_token(&head, &cur, tok);
	}
	return (head);
}
