/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:59:07 by codespace         #+#    #+#             */
/*   Updated: 2025/03/17 20:48:25 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

int	alloc_tokens(char *input)
{
	size_t	count;
	t_token	token;
	char	*actual_pos;
	int		command_found;

	count = 0;
	actual_pos = input;
	command_found = 0;
	while (*actual_pos)
	{
		token = ft_define_token_struct(&actual_pos, 0);
		if (token.type != PIPE && token.type != ERROR && token.type != END)
			free(token.value);
		if (token.type == COMMAND)
			command_found = 1;
		if (!ft_parse_error(token, command_found))
			return (-1);
		count++;
	}
	return (count);
}

int	tokenize_input(char **current_pos, t_token *tokens)
{
	t_token	token;
	int		commando_found;
	size_t	token_count;

	commando_found = 0;
	token_count = 0;
	while (**current_pos)
	{
		token = ft_define_token_struct(current_pos, commando_found);
		if (token.type == COMMAND)
			commando_found = 1;
		if (token.type == PIPE)
			commando_found = 0;
		if (token.type != ERROR)
			tokens[token_count++] = token;
		else
		{
			fprintf(stderr, "Error: Invalid token\n");
			ft_free_tokens(tokens);
			return (0);
		}
	}
	tokens[token_count].type = END;
	return (1);
}

int	ft_pipe_empty(t_token *tokens)
{
	int	i;
	int	pipe;
	int	commnad;

	i = 0;
	pipe = 0;
	commnad = 0;
	while (tokens[i].type != END)
	{
		if (tokens[i].type == COMMAND)
			commnad = 1;
		if (tokens[i].type == PIPE)
		{
			commnad = 0;
			pipe = 1;
		}
		i++;
	}
	if (pipe == 1 && commnad == 0)
	{
		ft_free_tokens(tokens);
		return (0);
	}
	return (1);
}

t_token	*lexer(char *input, t_mini *mini)
{
	t_token	*tokens;
	int		token_count;
	char	*current_pos;

	token_count = 0;
	current_pos = input;
	token_count = alloc_tokens(input);
	if (token_count == -1)
		return (NULL);
	tokens = malloc(sizeof(t_token) * (token_count + 1));
	if (!tokens)
		return (NULL);
	if (!tokenize_input(&current_pos, tokens))
		return (NULL);
	if (!ft_pipe_empty(tokens))
		return (ft_re_lexer(input, mini));
	return (tokens);
}

int	ft_parsing(t_mini *mini, t_token *tokens)
{
	int		i;
	char	*aux;
	char	*value;

	i = 0;
	value = NULL;
	while (tokens[i].type != END)
	{
		if (tokens[i].value)
		{
			aux = tokens[i].value;
			tokens[i].value = ft_has_dollar(aux, mini);
			if (ft_is_equal(tokens[i].value, ""))
				return (0);
			value = ft_quote(tokens[i].value, ft_strlen(tokens[i].value));
			free(tokens[i].value);
			tokens[i].value = value;
		}
		i++;
	}
	return (1);
}
