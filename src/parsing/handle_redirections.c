/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:01:47 by codespace         #+#    #+#             */
/*   Updated: 2025/02/24 12:26:40 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char *first_token_value = NULL;

void parse_redir(char *input)
{
    t_token *tokens;
    size_t i = 0;

    tokens = lexer(input);
    if (!tokens)
        return;
    if (tokens[i].type != END)
    {
        first_token_value = strdup(tokens[i].value);
    }

    free(tokens);
}

void test_parsing()
{
    char *test_cases[] = {
        "ls -l > file1 >> file2 < file3 << file4 | grep something $VAR $? p",
        NULL
    };

    for (int i = 0; test_cases[i] != NULL; i++)
    {
        printf("Test case %d: %s\n", i + 1, test_cases[i]);
        parse_redir(test_cases[i]);
        printf("\n");
    }
}

 int main() {
    test_parsing();
    return 0;
}
