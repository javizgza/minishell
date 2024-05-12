/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:12:58 by cagonza2          #+#    #+#             */
/*   Updated: 2023/09/27 16:05:49 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strlen(char const *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while ((src[i]) && (i < size - 1))
		{
			dst[i] = src[i];
			i += 1;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
