/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:22:55 by codespace         #+#    #+#             */
/*   Updated: 2024/05/19 16:49:09 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "unistd.h"

t_tokens    ft_define_tokens(char **token)
{
    while (ft_skip_white_spaces(token))
        (*token)++;
    if (**token == '\0')
        return (END);
    else if (**token == '|')
    {
        (*token)++;
        return (PIPE);
    }
    else if (**token == '>')
    {
        (*token)++;
        if (**token == '>')
        {
            (*token)++;
            return (BIGGERX2);
        }
        return (BIGGER);
    }
    else if (**token == '<')
    {
        (*token)++;
        if (**token == '<')
        {
            (*token)++;
            return (SMALLERX2);
        }
        return (SMALLER);
    }
    (*token)++;
    return (ERROR);
}

