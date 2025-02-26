/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:16:29 by jazarago          #+#    #+#             */
/*   Updated: 2025/02/25 20:37:04 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char *ft_substr2(char *s, int start, int len)
{
    char *substr = malloc(len + 1);
    if (!substr)
        return NULL;
    ft_strncpy(substr, s + start, len);
    //printf("Len: %i\n", len);
    substr[len] = '\0';
    return substr;
}

t_tokens    ft_define_tokens(char **token)
{
    ft_skip_white_spaces(token);
    if (**token == '\0')
        return (END);
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
    else if (**token == '|')
    {
        (*token)++;
        return (PIPE);
    }
    else if (**token == '$')
    {
        (*token)++;
        if (**token == '?')
        {
            (*token)++;
            return (RECENT);
        }
        return (ENV_VAR);
    }
    (*token)++;
    return (ERROR);
}

t_token ft_define_token_struct(char **token) 
{
    static int command_found = 0;
    t_token new_token;

    new_token.value = NULL;
    while (ft_skip_white_spaces(token))
        (*token)++;

    // End of string
    if (**token == '\0')
    {
        new_token.type = END;
        return new_token;
    }

    // Check for >> or >
    if (**token == '>')
    {
        (*token)++; 
        if (**token == '>')
        {
            new_token.type = BIGGERX2;
            (*token)++;
        }
        else
            new_token.type = BIGGER;

        // Skip spaces before file name
        ft_skip_white_spaces(token);
        // Gather next chunk as the token value
        {
            char *start = *token;
            size_t len = 0;
            while (**token && !ft_skip_white_spaces(token)
                && **token != '>' && **token != '<'
                && **token != '|' && **token != '$')
            {
                (*token)++;
                len++;
            }
            new_token.value = ft_substr2(start, 0, len);
        }
        return new_token;
    }

    // Check for << or <
    if (**token == '<')
    {
        (*token)++;
        if (**token == '<')
        {
            new_token.type = SMALLERX2;
            (*token)++;
        }
        else
            new_token.type = SMALLER;

        // Skip spaces before file name
        ft_skip_white_spaces(token);
        // Gather next chunk as the token value
        {
            char *start = *token;
            size_t len = 0;
            while (**token && !ft_skip_white_spaces(token)
                && **token != '>' && **token != '<'
                && **token != '|' && **token != '$')
            {
                (*token)++;
                len++;
            }
            new_token.value = ft_substr2(start, 0, len);
        }
        return new_token;
    }

    // Check for pipe
    if (**token == '|')
    {
        new_token.type = PIPE;
        (*token)++;
        return new_token;
    }

    // Check for $ variable
    if (**token == '$')
    {
        (*token)++;
        if (**token == '?')
        {
            new_token.type = RECENT;
            (*token)++;
        }
        else
            new_token.type = ENV_VAR;
        return new_token;
    }

    // Otherwise, it's some text. First becomes COMMAND, others become ARGUMENT
    {
        char *start = *token;
        size_t len = 0;
        while (**token && !ft_skip_white_spaces(token)
            && **token != '>' && **token != '<'
            && **token != '|' && **token != '$')
        {
            (*token)++;
            len++;
        }
        new_token.value = ft_substr2(start, 0, len);
        if (!command_found)
        {
            new_token.type = COMMAND;
            command_found = 1;
        }
        else
            new_token.type = COMMAND;
    }
    return new_token;
}
