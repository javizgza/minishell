/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:28:31 by carlos            #+#    #+#             */
/*   Updated: 2025/03/17 20:46:41 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

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
