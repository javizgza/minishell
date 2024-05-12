/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:06:28 by cagonza2          #+#    #+#             */
/*   Updated: 2023/10/04 19:30:42 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	equal(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
		if (s1[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	int		size;
	char	*result;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	while (equal(set, s1[i]) && s1[i])
		i += 1;
	while (equal(set, s1[size - 1]) && (size - 1))
		size -= 1;
	if (size < i)
		size = i;
	result = malloc(size - i + 1);
	if (!result)
		return (NULL);
	while (i < size)
		result[k++] = s1[i++];
	result[k] = '\0';
	return (result);
}
