/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierzaragozatejeda <javierzaragozatej    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:16:29 by jazarago          #+#    #+#             */
/*   Updated: 2025/01/04 19:21:49 by javierzarag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

    new_token.value = *token;
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
        new_token.type = COMMAND;
        while (**token && !ft_skip_white_spaces(token) && **token != '>' && **token != '<' && **token != '|' && **token != '$')
            (*token)++;
    }
    printf("Token: %s, Type: %d\n", new_token.value, new_token.type);
    return (new_token);
}
