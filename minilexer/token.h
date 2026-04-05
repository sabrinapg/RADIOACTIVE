#define STANDARD_BUFFER_SIZE 64

typedef enum s_type {
	NOTHING,
	WORD,
	PIPE,
	REDIR,
	AND,
	OR
}	t_type


typedef strudt s_token {
	char *token;
	t_type type;
	struct s_token *next;
} t_token;


#endif
