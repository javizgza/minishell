/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:26:08 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/11 15:49:43 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"


int	ft_is_equal(char *a, char *b)
{
	int	i;

	i = 0;
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i += 1;
	}
	return (1);
}