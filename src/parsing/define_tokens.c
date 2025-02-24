/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:16:29 by jazarago          #+#    #+#             */
/*   Updated: 2025/02/24 13:48:28 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char *ft_substr2(char *s, int start, int len) 
{
    char *substr = malloc(len + 1);
    if (!substr)
        return NULL;
    ft_strncpy(substr, s + start, len);
    printf("Len: %i\n", len);
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
    t_token new_token;

    new_token.value = NULL;
    while (ft_skip_white_spaces(token))
        (*token)++;
    if (**token == '\0')
        new_token.type = END;
    else if (**token == '>') 
    {
        (*token)++;
        if (**token == '>') 
        {
            new_token.type = BIGGERX2;
            (*token)++;
        }
        else 
            new_token.type = BIGGER;
    }
    else if (**token == '<') 
    {
        (*token)++;
        if (**token == '<') 
        {
            new_token.type = SMALLERX2;
            (*token)++;
        } 
        else 
            new_token.type = SMALLER;
    }
    else if (**token == '|') 
    {
        new_token.type = PIPE;
        (*token)++;
    }
    else if (**token == '$') 
    {
        (*token)++;
        if (**token == '?') 
        {
            new_token.type = RECENT;
            (*token)++;
        } 
        else 
            new_token.type = ENV_VAR;
    }
    else 
    {
        char *start = *token;
        size_t len = 1;

        while (**token && !ft_skip_white_spaces(token) && **token != '>' && **token != '<' && **token != '|' && **token != '$') 
        {
            (*token)++;
            len++;
        }
        new_token.value = ft_substr2(start, 0, len);
        new_token.type = COMMAND;
    }
    printf("Token: %s, Type: %d\n", new_token.value, new_token.type);
    return (new_token);
}
