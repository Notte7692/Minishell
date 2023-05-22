#include "minishell.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*str;

	i = 0;
	a = (unsigned char)c;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[0] = a;
		i++;
	}
	return (b);
}

t_elem create_elem( char *av)
{
	t_elem	*elem;

	if (av && av[0] != NULL)
	{
		elem = malloc(malloc(sizeof(t_elem));
		elem->value = ft_strdup(av)
		if (!elem->value)
			return (NULL);
		if (av[0] == '<')
			elem->type =  RED_INF;
		if (av[0] == '>')
			elem->type = RED_OUT;
		if (av[0] == "|")
			elem->type = PIPES;
		if (av[0] == "'")
			elem->type = SQUOTE;
		if (av[0] == '"')
			elem->type = DQUOTE;
		if (av[0] == "-")
			elem->typen = ARGS;
		else
			elem->type = COMMAND;
	}
}

t_token	*new_token(char **av)
{
	t_token	*token;

	token = malloc(sizeof *token);
	if (!token)
		return (NULL);
	token->previous = NULL;(av[1])
	token->next = NULL;
	token->elem = create_elem;
}

t_token	*add_token(char **av)
{
	t_token	*token;

	token = malloc(sizeof *token);
	if (!token)
		return (NULL);
	
	
}

t_token	create_stack(int nb, char **)
{
	t_token	*token_list;
	int	i;

	token_list = NULL;
	i = 0;
	while (i < nb)
	{
		if (i = 0)
			token_list = new_token;
		else
			token_list = add_token;
		i++;
	}
	return (token_list);
}

int main(int ac, char **av)
{
    int nb_args;
	
	nb_args = ac - 1;

}