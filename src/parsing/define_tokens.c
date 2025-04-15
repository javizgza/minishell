/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:16:29 by jazarago          #+#    #+#             */
/*   Updated: 2025/04/15 13:38:13 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

char	*ft_substr2(char *s, int start, int len)
{
	char	*substr;

	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strncpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}

int	ft_has_quotes(char	**str, t_token *new_token)
{
	int		len;
	int		quote;
	char	character;

	len = 1;
	character = **str;
	quote = -1;
	(*str)++;
	while (quote < 0 && **str)
	{
		if (**str == character)
			quote = 1;
		(*str)++;
		len++;
	}
	if (quote < 0)
	{
		new_token->type = ERROR;
		return (0);
	}
	return (len);
}

char	*ft_define_value(char **token, t_token *new_token)
{
	char	*result;
	char	*start;
	size_t	len;

	ft_skip_white_spaces(token);
	if (**token == '\0')
		return (NULL);
	start = *token;
	len = 0;
	while (**token && !ft_white_spaces(**token)
		&& **token != '>' && **token != '<' && **token != '|')
	{
		if (**token == '"' || **token == '\'')
			len += ft_has_quotes(token, new_token);
		else
		{
			(*token)++;
			len++;
		}
	}
	result = ft_substr_ignore_quotes(start, len);
	return (result);
}

t_token	ft_define_special_token(char **token, t_token new_token)
{
	if (**token == '>')
	{
		new_token.type = BIGGER;
		(*token)++;
		if (**token == '>')
		{
			new_token.type = BIGGERX2;
			(*token)++;
		}
	}
	else if (**token == '<')
	{
		new_token.type = SMALLER;
		(*token)++;
		if (**token == '<')
		{
			new_token.type = SMALLERX2;
			(*token)++;
		}
	}
	else
		new_token.type = PIPE;
	return (new_token);
}

t_token	ft_define_token_struct(char **token, int command_found)
{
	t_token		new_token;

	new_token.value = NULL;
	ft_skip_white_spaces(token);
	if (**token == '\0')
	{
		new_token.type = END;
		return (new_token);
	}
	else if (**token == '>' || **token == '<' || **token == '|')
	{
		new_token = ft_define_special_token(token, new_token);
		if (new_token.type != PIPE)
			new_token.value = ft_define_value(token, &new_token);
		else
			(*token)++;
		return (new_token);
	}
	if (command_found == 0)
		new_token.type = COMMAND;
	else
		new_token.type = ARGUMENT;
	new_token.value = ft_define_value(token, &new_token);
	return (new_token);
}
