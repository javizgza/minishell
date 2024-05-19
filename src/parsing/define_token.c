/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:22:55 by codespace         #+#    #+#             */
/*   Updated: 2024/05/19 17:19:06 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "unistd.h"

t_token ft_define_tokens(char **token)
{
    t_token result;
    result.value = NULL;

    while (ft_skip_white_spaces(token))
        (*token)++;
    if (**token == '\0')
    {
        result.type = END;
        return result;
    }
    else if (**token == '|')
    {
        (*token)++;
        result.type = PIPE;
        return result;
    }
    else if (**token == '>')
    {
        (*token)++;
        if (**token == '>')
        {
            (*token)++;
            result.type = BIGGERX2;
            return result;
        }
        result.type = BIGGER;
        return result;
    }
    else if (**token == '<')
    {
        (*token)++;
        if (**token == '<')
        {
            (*token)++;
            result.type = SMALLERX2;
            return result;
        }
        result.type = SMALLER;
        return result;
    }
    (*token)++;
    result.type = ERROR;
    return result;
}

