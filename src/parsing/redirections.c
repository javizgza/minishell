/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:35:36 by jazarago          #+#    #+#             */
/*   Updated: 2024/09/12 14:53:52 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    ft_set_up_redir(t_commands *command, t_tokens type, char **token)
{
    t_token    token_name;
    size_t n;

    token_name = ft_define_token_struct(token);
    if (type == BIGGER)
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
}

void    ft_set_up_redir2(t_commands *command, t_tokens type, char **token)
{
    t_token    token_name;
    size_t n;

    token_name = ft_define_token_struct2(token);
    if (type == PIPE)
        command->output = ft_strndup(token_name.value, n);
    else if (type == COMMAND)
        command->output_append = ft_strndup(token_name.value, n);
    else if (type == ARGUMENT)
        command->input = ft_strndup(token_name.value, n);
    else if (type == ENV_VAR)
        command->input_delim = ft_strndup(token_name.value, n);
}
