/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:01:47 by codespace         #+#    #+#             */
/*   Updated: 2024/05/19 17:53:46 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void parse_redir(char *input, t_commands *actual_command)
{
    char *actual_pos;
    t_token token;

    actual_pos = input;
    
    actual_command->command = NULL;
    actual_command->args = NULL;
    actual_command->args_num = 0;
    actual_command->input = NULL;
    actual_command->output = NULL;
    actual_command->output_append = NULL;
    actual_command->input_delim = NULL;

    while (true)
    {
        token = ft_define_tokens(&actual_pos);
        if (token.type == END)
            break;
        else if (token.type == ERROR)
        {
            printf("Syntax Error.\n");
            break;
        }
        if (token.type == BIGGER || token.type == SMALLER ||
                token.type == BIGGERX2 || token.type == SMALLERX2)
            ft_set_up_redir(actual_command, token.type, &token);
    }
     printf("Output file: %s\n", actual_command->output);
    printf("Append file: %s\n", actual_command->output_append);
    printf("Input file: %s\n", actual_command->input);
    printf("Input delimiter file: %s\n", actual_command->input_delim);
}


int main() {
    char input[] = "> >> < <<";  // Entrada simulada para redirecciones
    t_commands command;

    parse_redir(input, &command);

    // Limpieza (liberar la memoria asignada a los nombres de archivo)
    free(command.output);
    free(command.output_append);
    free(command.input);
    free(command.input_delim);

    return 0;
}