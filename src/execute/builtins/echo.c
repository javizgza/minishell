/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:28:31 by carlos            #+#    #+#             */
/*   Updated: 2025/04/03 12:30:33 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

int	ft_check_jump(char *first_arg)
{
	int	i;

	i = 1;
	while (first_arg[i] && first_arg[i] == 'n')
		i++;
	if (first_arg[i])
		return (1);
	return (0);
}

int	ft_echo(char **args)
{
	int	i;
	int	jump;

	i = 1;
	jump = 1;
	if (ft_nb_args(args) > 1)
	{
		if (args[1][0] == '-')
		{
			jump = ft_check_jump(args[1]);
			if (jump == 0)
				i++;
		}
		while (args[i] != NULL)
		{
			printf("%s", args[i]);
			if (args[i + 1])
				printf(" ");
			i++;
		}
	}
	if (jump)
		printf("\n");
	return (1);
}
