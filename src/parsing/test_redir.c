#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parsing.h"

// Implementación simulada de ft_define_token_struct
t_token ft_define_token_struct(char **token) {
    t_token new_token;
    new_token.value = *token;

    while (ft_skip_white_spaces(token))
        (*token)++;

    if (**token == '\0')
        new_token.type = END;
    else if (**token == '|') {
        new_token.type = PIPE;
        (*token)++;
    }
    else if (**token == '>') {
        (*token)++;
        if (**token == '>') {
            new_token.type = BIGGERX2;
            (*token)++;
        } else {
            new_token.type = BIGGER;
        }
    }
    else if (**token == '<') {
        (*token)++;
        if (**token == '<') {
            new_token.type = SMALLERX2;
            (*token)++;
        } else {
            new_token.type = SMALLER;
        }
    }
    else {
        new_token.type = ERROR;
    }
    return new_token;
}

// Implementación simulada de ft_strdup
char *ft_strdup(const char *s) {
    char *dup = malloc(strlen(s) + 1);
    if (dup) strcpy(dup, s);
    return dup;
}

// Implementación de ft_set_up_redir
void    ft_set_up_redir(t_commands *command, t_tokens type, char **token)
{
    t_token    token_name;

    token_name = ft_define_token_struct(token);
    if (type == BIGGER)
        command->output = ft_strdup(token_name.value);
    else if (type == BIGGERX2)
        command->output_append = ft_strdup(token_name.value);
    else if (type == SMALLER)
        command->input = ft_strdup(token_name.value);
    else if (type == SMALLERX2)
        command->input_delim = ft_strdup(token_name.value);
}

/* // Función main para probar ft_set_up_redir
int main() {
    char input[] = "> file1";
    char *current_position = input;
    t_token token;
    t_commands command = {0};

    // Obtén el token
    token = ft_define_token_struct(&current_position);

    // Prepara token_value para ft_set_up_redir
    char *token_value = token.value ? token.value : "";

    // Prueba la función
    ft_set_up_redir(&command, token.type, &token_value);

    // Verifica los resultados
    printf("Output file: %s\n", command.output ? command.output : "NULL");
    printf("Append file: %s\n", command.output_append ? command.output_append : "NULL");
    printf("Input file: %s\n", command.input ? command.input : "NULL");
    printf("Input delimiter file: %s\n", command.input_delim ? command.input_delim : "NULL");

    // Limpieza
    free(command.output);
    free(command.output_append);
    free(command.input);
    free(command.input_delim);

    return 0;
} */