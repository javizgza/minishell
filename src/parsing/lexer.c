/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:59:07 by codespace         #+#    #+#             */
/*   Updated: 2025/03/12 12:42:05 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute/include/execute.h"

size_t	alloc_tokens(char *input)
{
	size_t	count;
	t_token	token;
	char	*actual_pos;

	count = 0;
	actual_pos = input;
	while (*actual_pos)
	{
		token = ft_define_token_struct(&actual_pos, 0);
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
	int		commando_found;

	commando_found = 0;
	while (**current_pos)
	{
		token = ft_define_token_struct(current_pos, commando_found);
		if (token.type == COMMAND)
			commando_found = 1;
		if (token.type == PIPE)
			commando_found = 0;
		if (token.type != ERROR)
			tokens[(*token_count)++] = token;
		else
		{
			fprintf(stderr, "Error: Invalid token\n");
			ft_free_tokens(tokens);
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

int	ft_parsing(t_mini *mini, t_token *tokens)
{
	int		i;
	char	*aux;
	char	*processed_value;

	i = 0;
	processed_value = 0;
	while (tokens[i].type != END)
	{
		aux = tokens[i].value;
		tokens[i].value = ft_has_dolar(aux, mini->env, mini->last_command);
		if (ft_is_equal(tokens[i].value, ""))
			return (0);
		processed_value = ft_quote(tokens[i].value, ft_strlen(tokens[i].value));
		free(tokens[i].value);
		tokens[i].value = processed_value;
		i++;
	}
	return (1);
}
