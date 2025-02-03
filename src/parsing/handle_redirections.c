/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:01:47 by codespace         #+#    #+#             */
/*   Updated: 2024/09/12 14:55:10 by jazarago         ###   ########.fr       */
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
        if (token_type == BIGGER || token_type == SMALLER ||
                token_type == BIGGERX2 || token_type == SMALLERX2 ||
                    token_type == ENV_VAR || token_type == RECENT || token_type == PIPE)
            ft_set_up_redir(actual_command, token_type, &actual_pos);
        // if (token_type == PIPE || token_type == RECENT || token_type == ENV_VAR)
        // {
        //     ft_set_up_redir2(actual_command, token_type, &actual_pos);
        // }
    }
    printf("Output file: %s\n", actual_command->output ? actual_command->output : "NULL");
    printf("Append file: %s\n", actual_command->output_append ? actual_command->output_append : "NULL");
    printf("Input file: %s\n", actual_command->input ? actual_command->input : "NULL");
    printf("Input delimiter file: %s\n", actual_command->input_delim ? actual_command->input_delim : "NULL");
    printf("Env var: %s\n", actual_command->env_var ? actual_command->env_var : "NULL");
    printf("Pipes: %s\n", actual_command->pipes ? actual_command->pipes : "NULL");
    printf("Recent: %s\n", actual_command->recent ? actual_command->recent : "NULL");
}

int main() {
    char input[] = "> file1 >> file2 < file3 << file4 | grep something $VAR $? p"; 
    parse_redir(input);
    return 0;
}
