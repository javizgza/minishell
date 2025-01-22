/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierzaragozatejeda <javierzaragozatej    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:01:47 by codespace         #+#    #+#             */
/*   Updated: 2025/01/21 15:27:12 by javierzarag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    parse_redir(char *input)
{
    t_token *tokens;
    t_commands *actual_command;
    size_t i = 0;

    actual_command = malloc(sizeof(t_commands));
    if (!actual_command)
        return;
    memset(actual_command, 0, sizeof(t_commands)); // Initialize the structure
    actual_command->args = malloc(sizeof(char *) * 1024); // Allocate memory for args
    if (!actual_command->args)
    {
        free(actual_command);
        return;
    }
    actual_command->args_num = 0;

    tokens = lexer(input);
    if (!tokens)
    {
        free(actual_command->args);
        free(actual_command);
        return;
    }
    while (tokens[i].type != END)
    {
        ft_set_up_redir(actual_command, tokens[i].type, &tokens[i].value);
        i++;
    }
    actual_command->args[actual_command->args_num] = NULL; // Null-terminate the args array
    execute_commands(actual_command);

    free(tokens);
    free(actual_command->args);
    free(actual_command);
}

void test_parsing()
{
    char *test_cases[] = {
        "> file1 >> file2 < file3 << file4 | grep something $VAR $? p",
        "command1 arg1 arg2 > output_file",
        "command2 < input_file | command3 >> append_file",
        "invalid_token > file",
        "command4 | command5 $HOME",
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
