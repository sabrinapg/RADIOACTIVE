/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:32:01 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/04/05 17:32:52 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

static t_token	*new_token(char *value, t_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = value;
	token->type = type;
	token->next = NULL;
	return (token);
}

static t_token	*get_redir_in(const char *s, int *i)
{
	if (s[*i + 1] == '<')
	{
		(*i) += 2;
		return (new_token(ft_strdup("<<"), TOKEN_HEREDOC));
	}
	(*i)++;
	return (new_token(ft_strdup("<"), TOKEN_REDIR_IN));
}

static t_token	*get_redir_out(const char *s, int *i)
{
	if (s[*i + 1] == '>')
	{
		(*i) += 2;
		return (new_token(ft_strdup(">>"), TOKEN_REDIR_APP));
	}
	(*i)++;
	return (new_token(ft_strdup(">"), TOKEN_REDIR_OUT));
}

t_token	*ft_get_operator(const char *s, int *i)
{
	if (s[*i] == '|')
	{
		(*i)++;
		return (new_token(ft_strdup("|"), TOKEN_PIPE));
	}
	if (s[*i] == '<')
		return (get_redir_in(s, i));
	if (s[*i] == '>')
		return (get_redir_out(s, i));
	return (NULL);
}

t_token	*ft_new_word(const char *s, int start, int len)
{
	return (new_token(ft_substr(s, start, len), TOKEN_WORD));
}
