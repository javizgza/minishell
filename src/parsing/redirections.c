/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:35:36 by jazarago          #+#    #+#             */
/*   Updated: 2024/09/11 16:41:07 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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