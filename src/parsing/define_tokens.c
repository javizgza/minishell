#include "parsing.h"

t_tokens    ft_define_tokens(char **token)
{
    ft_skip_white_spaces(token);
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

t_token ft_define_token_struct(char **token) {
    t_token new_token;
    new_token.value = *token;

    while (ft_skip_white_spaces(token))
        (*token)++;

    if (**token == '\0')
        new_token.type = END;
    else if (**token == '|') {
        new_token.type = PIPE;
        (*token)++;
    }
    else if (**token == '>') {
        (*token)++;
        if (**token == '>') {
            new_token.type = BIGGERX2;
            (*token)++;
        } else {
            new_token.type = BIGGER;
        }
    }
    else if (**token == '<') {
        (*token)++;
        if (**token == '<') {
            new_token.type = SMALLERX2;
            (*token)++;
        } else {
            new_token.type = SMALLER;
        }
    }
    else {
        new_token.type = ERROR;
    }
    return new_token;
}
