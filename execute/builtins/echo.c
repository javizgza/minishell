/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:07:30 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/14 15:53:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_echo(char **args)
{
	int	i;
	int	jump;

	i = 1;
	jump = 1;
	if (ft_is_equal(args[1], "-n"))
		jump = 0;
	while (args[i] != NULL)
	{
		printf("%s ", args[i]);
		i += 1;
	}
	if (jump)
		printf("\n");
	return (ft_strlen(args[0]));
}