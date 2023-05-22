#include "minishell.h"

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

        if (head == NULL) {
            head = node;
            current = node;
        } else {
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
    char *av[] = {"command", "arg1", "<", "|", "env_var", NULL};

    t_token *token_stack = create_token_stack(av);
    print_token_stack(token_stack);

    // Free the allocated memory
    free_token_stack(token_stack);

    return 0;
}