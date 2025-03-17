/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:46:45 by jazarago          #+#    #+#             */
/*   Updated: 2025/03/17 20:44:38 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

void	ft_free_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].type != END && tokens[i].type != ERROR)
	{
		if (tokens[i].type != PIPE && tokens[i].type != END)
			free(tokens[i].value);
		i++;
	}
	free (tokens);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*result;
	int		size;
	int		i;

	size = ft_strlen(s) + 1;
	(void) n;
	result = (char *)malloc(size * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

t_token	*ft_re_lexer(char *input, t_mini *mini)
{
	char	*aux;
	char	*join_res;
	char	*join_aux;

	aux = readline(">");
	join_aux = ft_strjoin(" ", aux);
	free(aux);
	join_res = ft_strjoin(input, join_aux);
	free(input);
	free(join_aux);
	mini->line = join_res;
	return (lexer(join_res, mini));
}

int	ft_parse_error(t_token token, int command_found)
{
	if (token.type != END && token.type != PIPE && !token.value)
	{
		free(token.value);
		ft_error("syntax error near unexpected token `newline'\n");
		return (0);
	}
	if (token.type == PIPE && command_found == 0)
	{
		ft_error("syntax error near unexpected token `|'\n");
		return (0);
	}
	return (1);
}
