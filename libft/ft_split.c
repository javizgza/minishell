/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:58:00 by cagonza2          #+#    #+#             */
/*   Updated: 2023/10/08 11:51:18 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_allocate(char **result, char const *s, char c)
{
	char const	*aux;

	aux = s;
	while (*aux)
	{
		while (*s == c)
			s += 1;
		aux = s;
		while (*aux && *aux != c)
			aux += 1;
		if (*aux == c || aux > s)
		{
			*result = ft_substr(s, 0, aux - s);
			s = aux;
			result += 1;
		}
	}
	*result = NULL;
}

static int	ft_speclen(char const *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != c)
			counter += 1;
		while (str[i] != c && str[i])
			i += 1;
		i += 1;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;

	if (!s)
		return (NULL);
	size = ft_speclen(s, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	ft_allocate(result, s, c);
	return (result);
}
