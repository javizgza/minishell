/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:16:29 by jazarago          #+#    #+#             */
/*   Updated: 2025/03/11 11:29:28 by jazarago         ###   ########.fr       */
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
int	ft_has_quotes(char	**str, t_token *token)
{
	int		len;
	char	quote;
	char	*start;

	len = 0;
	if (**str == '"' || **str == '\'')
	{
		quote = **str;
		(*str)++;
		len++;
		start = *str;
		while (**str)
		{
			if (**str == quote)
			{
				token->value = ft_substr2(start, 0, len - 1);
				token->type = COMMAND;
				return (0);
			}
			len++;
			(*str)++;
		}
	}
	return (1);
}

t_token ft_define_token_struct(char **token) 
{
    static int command_found = 0;
    t_token new_token;

    new_token.value = NULL;
    ft_skip_white_spaces(token);
	if (!ft_has_quotes(token, &new_token))
		return (new_token);
    if (**token == '\0')
    {
        new_token.type = END;
        return new_token;
    }
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
        ft_skip_white_spaces(token);
        {
            char *start = *token;
            size_t len = 0;
            while (**token && !ft_white_spaces(**token)
                && **token != '>' && **token != '<'
                && **token != '|')
            {
                (*token)++;
                len++;
            }
            new_token.value = ft_substr_ignore_quotes(start, len);
        }
        return new_token;
    }
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
        ft_skip_white_spaces(token);
        {
            char *start = *token;
            size_t len = 0;
            while (**token && !ft_white_spaces(**token)
                && **token != '>' && **token != '<'
                && **token != '|')
            {
                (*token)++;
                len++;
            }
            new_token.value = ft_substr_ignore_quotes(start, len);
        }
        return new_token;
    }
    if (**token == '|')
    {
        new_token.type = PIPE;
        (*token)++;
        return new_token;
    }

/*     // Check for $ variable
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
    } */
    {
        char *start = *token;
        size_t len = 0;
        while (**token
            && **token != '>' && **token != '<'
            && **token != '|')
        {
            (*token)++;
            len++;
        }
        new_token.value = ft_substr_ignore_quotes(start, len);
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
