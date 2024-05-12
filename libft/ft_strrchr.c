/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_strrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:59:00 by cagonza2          #+#    #+#             */
/*   Updated: 2023/10/08 12:37:46 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int	i;
	int	last;

	i = 0;
	last = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == (char)c)
			last = i;
		i += 1;
	}
	if (s[i] == (char)c)
		return ((char *)&s[last]);
	if (last != ft_strlen(s) && s[last] != '\0')
		return ((char *)&s[last]);
	return (NULL);
}
