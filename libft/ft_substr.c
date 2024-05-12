/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:06:37 by cagonza2          #+#    #+#             */
/*   Updated: 2023/10/08 12:28:37 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s || (long int)len < 0)
		return (NULL);
	if (len > (size_t)ft_strlen(s))
		len = ft_strlen(s);
	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (s[start + i] && i < len)
	{
		result[i] = s[start + i];
		i += 1;
	}
	result[i] = '\0';
	return (result);
}
