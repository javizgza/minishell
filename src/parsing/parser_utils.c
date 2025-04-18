/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:26:18 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 13:10:27 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

char	*ft_substr_ignore_quotes(char *start, size_t len)
{
	char	*result;
	char	*res_ptr;
	char	*end;

	result = malloc(len + 1);
	res_ptr = result;
	end = start + len;
	while (start < end)
	{
		*res_ptr++ = *start;
		start++;
	}
	*res_ptr = '\0';
	return (result);
}

char	*ft_quote(char *start, size_t len)
{
	char	*result;
	char	*res_ptr;
	char	*end;
	int		quote;
	int		quote_s;

	result = malloc(len + 1);
	res_ptr = result;
	end = start + len;
	quote = 1;
	quote_s = 1;
	while (start < end)
	{
		if (*start == '\'' && quote > 0)
			quote_s *= -1;
		if (*start == '\"' && quote_s > 0)
			quote *= -1;
		if ((*start == '\'' && quote < 0) || (*start == '\"' && quote_s < 0))
			*res_ptr++ = *start;
		else if (*start != '\'' && *start != '\"')
			*res_ptr++ = *start;
		start++;
	}
	*res_ptr = '\0';
	return (result);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
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

int	ft_white_spaces(char c)
{
	return ((c == ' ') || (c >= 9 && c <= 15));
}

int	ft_skip_white_spaces(char **token)
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
