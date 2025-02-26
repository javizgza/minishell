/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:59:07 by codespace         #+#    #+#             */
/*   Updated: 2025/02/26 14:00:02 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	alloc_tokens(char *input)
{
	size_t	count;
	t_token	token;
	char	*actual_pos;

	count = 0;
	actual_pos = input;
	while (*actual_pos)
	{
		token = ft_define_token_struct(&actual_pos);
		if (token.type != PIPE && token.type != ERROR)
			free(token.value);
		if (token.type != ERROR)
			count++;
	}
	return (count);
}

int	tokenize_input(char **current_pos, t_token *tokens, size_t *token_count)
{
	t_token	token;

	while (**current_pos)
	{
		token = ft_define_token_struct(current_pos);
		if (token.type != ERROR)
			tokens[(*token_count)++] = token;
		else
		{
			fprintf(stderr, "Error: Invalid token\n");
			free(tokens);
			return (0);
		}
	}
	tokens[*token_count].type = END;
	return (1);
}

t_token	*lexer(char *input)
{
	t_token	*tokens;
	size_t	token_count;
	char	*current_pos;

	token_count = 0;
	current_pos = input;
	tokens = malloc(sizeof(t_token) * (alloc_tokens(input) + 1));
	if (!tokens)
		return (NULL);
	if (!tokenize_input(&current_pos, tokens, &token_count))
		return (NULL);
	return (tokens);
}
