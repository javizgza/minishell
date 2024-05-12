/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:13:12 by cagonza2          #+#    #+#             */
/*   Updated: 2023/10/01 18:25:23 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i])
		i += 1;
	k = 0;
	while (src[k])
		k += 1;
	if (size <= i)
		k += size;
	else
		k += i;
	j = 0;
	while (src[j] && (i + 1) < size)
	{
		dst[i] = src[j];
		i += 1;
		j += 1;
	}
	dst[i] = '\0';
	return (k);
}
