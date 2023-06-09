#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef enum
{
	COMMAND = 0,
	ARGS,
	RED_INF,
	RED_OUT,
	PIPES,
	ENV_VAR,
	SUBSTITUTE,
	SQUOTE,
	DQUOTE,
}	arg_type;

typedef struct s_elem
{
	char	*value;
	arg_type	type;
}	t_elem;

typedef struct s_stack
{
	t_elem *elem;
	struct s_stack	*previous;
	struct s_stack *next;
}	t_token;


#endif
