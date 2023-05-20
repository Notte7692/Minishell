#ifndef MINISHELL_H
# define MINISHELL_H

typedef s_token
{
	char	*value;
	char	*type;	
} t_token;

typedef s_stack
{
	t_token *token;
	s_stack	*previous;
	s_stack *next;
}	t_stack;

enum Args_type
{
	SCOTE,
	DCOTE,
	PARENTHESIS,
	CMD,
	PIPE,
	LCHEVRON,
	RCHEVRON,
}
#endif
