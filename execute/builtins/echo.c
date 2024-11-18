/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:07:30 by cagonza2          #+#    #+#             */
/*   Updated: 2024/11/18 12:33:22 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_echo(char **args, t_mini *mini)
{
	int	i;
	int	jump;

	i = 1;
	jump = 1;
	mini->last_command = 0;
	if (ft_nb_args(args) > 1)
	{
		if (ft_is_equal(args[1], "-n"))
		{
			jump = 0;
			i++;
		}
		while (args[i] != NULL)
		{
			printf("%s ", args[i]);
			i++;
		}
	}
	if (jump)
		printf("\n");
	return (1);
}
