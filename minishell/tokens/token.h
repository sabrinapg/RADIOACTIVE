/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:30:07 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/04/05 17:33:09 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APP,
	TOKEN_HEREDOC,
}	t_type;

typedef struct s_token
{
	char	*value;
	t_type	type;
	struct s_token *next;
}	t_token;

typedef struct s_cmd
{
	char	**args;
	char	*infile;
	char	*outfile;
	int		append;
	char	*heredoc;
	struct s_cmd	*next;
}	t_cmd;

t_token *ft_get_operator(const char *s, int *i);
t_token *ft_lexer(const char *s);

#endif
