/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:26:18 by codespace         #+#    #+#             */
/*   Updated: 2024/09/11 17:04:31 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int ft_white_spaces(char c)
{
    return ((c == ' ') || (c >= 9 && c<= 15));
}

int ft_skip_white_spaces(char **token)
{
    while (ft_white_spaces(**token))
        (*token)++;
    return (0);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	int		size;
	int		i;

	size = ft_strlen(s) + 1;
	result = (char *)malloc(size * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i += 1;
	}
	result[i] = '\0';
	return (result);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}
