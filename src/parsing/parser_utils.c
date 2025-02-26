/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:26:18 by codespace         #+#    #+#             */
/*   Updated: 2025/02/26 12:36:53 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char *ft_strncpy(char *dest, const char *src, size_t n) 
{
    size_t i = 0;

    while (i < n && src[i] != '\0') 
	{
        dest[i] = src[i];
        i++;
    }
    while (i < n) 
	{
        dest[i] = '\0';
        i++;
	}
    return (dest);
}

int ft_white_spaces(char c)
{
    return ((c == ' ') || (c >= 9 && c<= 15));
}

int ft_skip_white_spaces(char **token)
{
	int	yes;

	yes = 0;
    while (ft_white_spaces(**token))
	{
        (*token)++;
		yes = 1;
	}
    return (yes);
}

void	ft_free_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].type != END)
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
