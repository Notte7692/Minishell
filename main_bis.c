#include "minishell.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

char	**tab(char *av)
{
	int	i;
	int	start;
	int	end;
	char	**tab;
	char *str;
	
	str = ft_strtrim(av, " ");
	i = 0;
	while(av && av[i] && av[i] == ' ')
		i++;
	while(av && av[i])
	{
		start = i;
		while (av[i] && av[i] >= 'a' && av[i] )
	}
}

t_token *create_token_stack(char **av)
{
    t_token *head = NULL;
    t_token *current = NULL;

    for (int i = 0; av[i] != NULL; i++) {
        t_elem *elem = malloc(sizeof(t_elem));
        elem->value = strdup(av[i]);

        if (av[i][0] == '<' ) 
            elem->type = RED_INF;
        else if (av[i][0] == '>')
            elem->type = RED_OUT;
        else if (av[i][0] == '|')
            elem->type = PIPES;
        else if (av[i][0] == '\'')
            elem->type = SQUOTE;
        else
            elem->type = COMMAND;

        // Create a new token node
        t_token *node = malloc(sizeof(t_token));
        node->elem = elem;
        node->previous = NULL;
        node->next = NULL;

        if (head == NULL)
        {
            head = node;
            current = node;
        }
        else
        {
            current->next = node;
            node->previous = current;
            current = node;
        }
    }

    return head;
}

void print_token_stack(t_token *head) {
    t_token *current = head;
    while (current != NULL) {
        printf("Value: %s, Type: %d\n", current->elem->value, current->elem->type);
        current = current->next;
    }
}

void free_token_stack(t_token *head) {
    t_token *current = head;
    while (current != NULL) {
        t_token *temp = current;
        current = current->next;
        free(temp->elem->value);  // Free the allocated value
        free(temp->elem);
        free(temp);
    }
}

int main() {
    char *av[] = {"<command", "arg1", "<", "|", "env_var", NULL};

    t_token *token_stack = create_token_stack(av);
    print_token_stack(token_stack);

    // Free the allocated memory
    free_token_stack(token_stack);

    return 0;
}