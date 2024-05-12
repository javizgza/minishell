/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:04:53 by cagonza2          #+#    #+#             */
/*   Updated: 2023/10/04 19:24:51 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += 1;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		i += 1;
		n /= 10;
	}
	return (i);
}

static char	*ft_min(void)
{
	unsigned int	min;
	int				digit;
	char			*num;

	min = 2147483648;
	digit = 11;
	num = (char *)malloc(sizeof(char) * (digit + 1));
	num[0] = '-';
	while (min > 0)
	{
		num[--digit] = (min % 10) + '0';
		min /= 10;
	}
	num[11] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		digit;

	if (n == -2147483648)
		return (ft_min());
	digit = ft_digit(n);
	num = (char *)malloc(sizeof(char) * (digit + 1));
	if (!num)
		return (NULL);
	else if (n == 0)
		num[0] = '0';
	else if (n < 0)
	{
		num[0] = '-';
		n = -n;
	}
	num[digit] = '\0';
	while (n > 0)
	{
		num[--digit] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}
