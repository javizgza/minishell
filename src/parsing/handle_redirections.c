/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:01:47 by codespace         #+#    #+#             */
/*   Updated: 2024/09/11 17:51:49 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    parse_redir(char *input)
{
    char        *actual_pos;
    t_commands  *actual_command;
    
    actual_pos = input;
    actual_command = malloc(sizeof(t_commands));
    while (true)
    {
        while (*actual_pos != '<' && *actual_pos != '>' && *actual_pos)
            actual_pos++;
        t_tokens token_type = ft_define_tokens(&actual_pos);
        if (token_type == END)
            break;
        // else if (token_type == ERROR)
        // {
        //     printf("Syntax Error.\n");
        //     break;
        //     printf("hoola\n");
        // }
        if (token_type == BIGGER || token_type == SMALLER ||
                token_type == BIGGERX2 || token_type == SMALLERX2)
        {
                ft_set_up_redir(actual_command, token_type, &actual_pos);
                
        }
    }
    printf("Output file: %s\n", actual_command->output ? actual_command->output : "NULL");
    printf("Append file: %s\n", actual_command->output_append ? actual_command->output_append : "NULL");
    printf("Input file: %s\n", actual_command->input ? actual_command->input : "NULL");
    printf("Input delimiter file: %s\n", actual_command->input_delim ? actual_command->input_delim : "NULL");
}

int main() {
    char input[] = "> file1 >> file2 < file3 << file4";
    parse_redir(input);
    return 0;
}

// int main() {
//     char input[] = "> >> < <<";
//     char *current_position = input;
//     t_commands command = {0};

//     while (true) {
//         t_tokens token_type = ft_define_tokens(&current_position);
//         if (token_type == END) {
//             break;
//         } else {
//             ft_set_up_redir(&command, token_type, &current_position);
//         }
//     }
//     printf("Output file: %s\n", command.output);
//     printf("Append file: %s\n", command.output_append);
//     printf("Input file: %s\n", command.input);
//     printf("Input delimiter file: %s\n", command.input_delim);
//     return (0);
// }