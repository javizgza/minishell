/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:40:24 by cagonza2          #+#    #+#             */
/*   Updated: 2023/10/08 12:47:00 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_pos(const char *str, const char *to_find, size_t pos)
{
	char	find_lst;
	size_t	i;

	find_lst = to_find[ft_strlen(to_find) - 1];
	i = pos;
	while (find_lst != str[i])
		i += 1;
	if (ft_strlen(to_find) > 1 && str[i - 1] != to_find[ft_strlen(to_find) - 2])
		return (ft_strlen(str) - 1);
	return (i);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!str || !to_find) && size == 0)
		return (NULL);
	if (!to_find[i] || to_find == str)
		return ((char *)str);
	if (size < 0)
		size = ft_strlen(str) + size;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
			{
				if (ft_pos(str, to_find, i) < size)
					return ((char *)&str[i]);
			}
			j += 1;
		}
		i += 1;
	}
	return (0);
}
