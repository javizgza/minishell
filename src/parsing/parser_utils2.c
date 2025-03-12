/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:46:45 by jazarago          #+#    #+#             */
/*   Updated: 2025/03/12 12:48:00 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_free_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].type != END && tokens[i].type)
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
