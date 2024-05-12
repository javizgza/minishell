/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:13:50 by cagonza2          #+#    #+#             */
/*   Updated: 2023/10/04 19:23:29 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check_space(char first)
{
	if (first == '\n')
		return (1);
	else if (first == '\t')
		return (1);
	else if (first == '\v')
		return (1);
	else if (first == '\f')
		return (1);
	else if (first == '\r')
		return (1);
	else if (first == ' ')
		return (1);
	return (0);
}

static int	ft_part(const char *str, int num, int sig, int i)
{
	while (str[i])
	{
		if (ft_check_space(str[i]) == 0)
			break ;
		i += 1;
	}
	if (str[i] == '-')
	{
		sig *= -1;
		i += 1;
	}
	else if (str[i] == '+')
		i += 1;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			num = (str[i] - '0') + (num * 10);
		else
			break ;
		i += 1;
	}
	return (num * sig);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sig;
	int	i;

	num = 0;
	sig = 1;
	i = 0;
	return (ft_part(str, num, sig, i));
}
