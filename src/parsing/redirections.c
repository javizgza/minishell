/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:35:36 by jazarago          #+#    #+#             */
/*   Updated: 2024/05/19 17:12:14 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void ft_set_up_redir(t_commands *command, t_tokens type, t_token *token)
{
    char *token_value;

    token_value = token->value;

    if (type == BIGGER)
        command->output = ft_strdup(token_value);
    else if (type == BIGGERX2)
        command->output_append = ft_strdup(token_value);
    else if (type == SMALLER)
        command->input = ft_strdup(token_value);
    else if (type == SMALLERX2)
        command->input_delim = ft_strdup(token_value);
}
