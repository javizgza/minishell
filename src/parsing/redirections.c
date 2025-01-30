/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:35:36 by jazarago          #+#    #+#             */
/*   Updated: 2025/01/30 14:36:16 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    ft_set_up_redir(t_commands *command, t_tokens type, char **token)
{
    t_token    token_name;
    size_t n;

    token_name = ft_define_token_struct(token);
    n = strlen(token_name.value);
    if (type == ENV_VAR)
    {
        char *env_value = getenv(token_name.value);
        if (env_value)
            command->env_var = ft_strndup(env_value, strlen(env_value));
        else
            command->env_var = ft_strndup(token_name.value, n);
    }
    else if (type == BIGGER)
        command->output = ft_strndup(token_name.value, n);
    else if (type == BIGGERX2)
        command->output_append = ft_strndup(token_name.value, n);
    else if (type == SMALLER)
        command->input = ft_strndup(token_name.value, n);
    else if (type == SMALLERX2)
        command->input_delim = ft_strndup(token_name.value, n);
    else if (type == ENV_VAR)
        command->env_var = ft_strndup(token_name.value, n);
    else if (type == RECENT)
        command->recent = ft_strndup(token_name.value, n);
    else if (type == PIPE)
        command->pipes = ft_strndup(token_name.value, n);
    else if (type == COMMAND || type == ARGUMENT)
    {
        if (!command->command)
            command->command = ft_strndup(token_name.value, n);
        else
            command->args[command->args_num++] = ft_strndup(token_name.value, n);
    }
}

/*  int main()
{
    t_commands command = {0};
    char *token = "PATH";
    setenv("HOME", "/home/user", 1);

    ft_set_up_redir(&command, ENV_VAR, &token);

    printf("Environment Variable Value: %s\n", command.env_var);

    // Free allocated memory
    free(command.env_var);

    return 0;
} */
