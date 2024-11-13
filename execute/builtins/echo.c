/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:07:30 by cagonza2          #+#    #+#             */
/*   Updated: 2024/11/13 12:34:46 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_echo(char **args, t_mini *mini)
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
	mini->last_command(ft_strlen(args[0]));
	return (ft_strlen(args[0]));
}
