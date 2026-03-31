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

static t_token	*get_operator(const char *s, int *i)
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

static t_token	*get_word(const char *s, int *i)
{
	int		start;
	char	*value;

	start = *i;
	while (s[*i] && s[*i] != ' ' && s[*i] != '|'
		&& s[*i] != '<' && s[*i] != '>')
		(*i)++;
	value = ft_substr(s, start, *i - start);
	return (new_token(value, TOKEN_WORD));
}

t_token			*ft_lexer(const char *s)
{
	t_token	*head;
	t_token	*current;
	t_token	*token;
	int		i;

	head = NULL;
	current = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else if (s[i] == '|' || s[i] == '<' || s[i] == '>')
			token = get_operator(s, &i);
		else
			token = get_word(s, &i);
		if (token)
		{
			if (!head)
				head = token;
			else
				current->next = token;
			current = token;
		}
	}
	return (head);
}

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
	return (new_token(ft_substr(s, start, *i - start), TOKEN_WORD));
}

static void	add_token(t_token **head, t_token **current, t_token *token)
{
	if (!*head)
		*head = token;
	else
		(*current)->next = token;
	*current = token;
}

t_token		*ft_lexer(const char *s)
{
	t_token	*head;
	t_token	*current;
	t_token	*token;
	int		i;

	head = NULL;
	current = NULL;
	i = 0;
	while (s[i])
	{
		token = NULL;
		if (s[i] == ' ')
			i++;
		else if (s[i] == '|' || s[i] == '<' || s[i] == '>')
			token = get_operator(s, &i);
		else
			token = get_word(s, &i);
		if (token)
			add_token(&head, &current, token);
	}
	return (head);
}
