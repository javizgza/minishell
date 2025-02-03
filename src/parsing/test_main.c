
#include "parsing.h"

// ...existing code...

int main(void)
{
    char *inputs[] = {
        "echo single_quote 'test",
        "echo double_quote \"hello $USER\"",
        "echo no_quotes '$HOME",
        "echo pipe | grep something",
        "echo unmatched_quote \"test",
        NULL
    };
    int i = 0;

    while (inputs[i] != NULL)
    {
        printf("Testing input: %s\n", inputs[i]);
        t_token *tokens = lexer(inputs[i]);
        if (!tokens)
        {
            printf("Lexer returned NULL or ERROR.\n\n");
            i++;
            continue;
        }
        // Display resulting tokens
        int j = 0;
        while (tokens[j].type != END)
        {
            printf("Token %d => Type: %d, Value: '%s'\n",
                   j, tokens[j].type, tokens[j].value);
            j++;
        }
        free(tokens);
        printf("\n");
        i++;
    }
    return 0;
}