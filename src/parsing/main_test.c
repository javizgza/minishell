#include "parsing.h"
#include <stdio.h>

int main(void)
{
    char input[] = "ls > out.txt";
    t_token *tokens = lexer(input);

    if (!tokens)
    {
        fprintf(stderr, "Lexer returned NULL\n");
        return 1;
    }

    size_t i = 0;
    while (tokens[i].type != END)
    {
        printf("Token %zu: Type = %d, Value = %s\n", i, tokens[i].type, tokens[i].value);
        i++;
    }

    free(tokens); // Don't forget to free allocated memory
    return 0;
}