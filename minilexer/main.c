#include "TOKEN_H"


int	main(int argv, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	char *line;
	t_tokens *tokens;

	while (1)
	{
		line = ft_readline("pdshell> ");
		tokens = tokenise(line);
		print_tokens(tokens);
		if (line)
			free(line);
	}
}


t_token *tokenise(char *line)
{
	int i;
	t_token *ret;
	t_token *head;
	int diff;
	init_tokens(&head);
	ret = head;
	i = 0;
	while(line[i])
	{
		diff = 0;
		i = skip_spaces(line, i);
		diff = handle_operator(&line[i], &ret);
		if (diff)
		{
			i += diff;
			continue;
		}
		diff = handle_redirections(&line[i])
		if (diff)
		{
			i += diff;
			continue;
		}
		diff = handle_world(&line[i], &ret);
		if (diff)
		{
			i = diff;
			continue;
		}
		i++;
	}
}

int	handle_redirections(char *line, t_token **tokens)
{
	int i = 0;
	if (line[i] == '<' && line [i + 1] && line[i + 1] != '<')
	{
		add_node_info(tokens, REDIR, "<");
		*tokens = (*tokens)->next;
		i++;
	}
	else if (line[i] == '<' && line[i + 1] && line[i + 1] == '<')
	{
		add_node_info(tokens, REDIR, "<<");
		*tokens = (*tokens)->next;
		i += 2;
	}
	else if (line[i] == '>' && line[i + 1] && line[i + 1] == '>')
	{
		add_node_info(tokens, REDIR, ">>");
		*tokens = (*tokens)->next;
		i += 2;
	}
	else if (line[i] == '>' && line[i + 1] && line[i + 1] != '>')
	{
		add_node_info(tokens, REDIR, ">");
		*tokens = (*tokens)->next;
		i++;
	}
	return (i);
}

int	handle_world(char *line, t_token **tokens)
{
	int i = 0;
	char *ret;
	while (line[i] && !isspace(line[i]))
		i++;
	if (i == 0)
		return (0);
	ret = malloc(sizeof(i + 1));
	ret = strncpy(ret, line, i);
	ret[i] = '\0';
	add_node_info(tokens, REDIR, ret);
	*tokens = (*tokens)->next;
	return (i);
}

static void add_node_info(t_token **tokens, t_type type, char *token)
{
	init_tokens(&(*tokens)->next);
	(*tokens)->type = yype;
	(*tokens)->token = token;
}

int	skip_spaces(char *line, int i)
{
	while (isspace(line[i]))
		i++;
	return (i);
}

int handle_operator(char *line, t_token **tokens)
{
	int i = 0;
	if (line[i] == '|' && line[i + 1] && line[i + 1] != '|')
	{
		add_node_info(token`)

	}
	else if
	{


	}
	else if ()
	{

	}
	return (i);
}
