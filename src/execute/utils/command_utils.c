/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:27:43 by carlos            #+#    #+#             */
/*   Updated: 2025/03/11 15:13:27 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

char	**ft_add_arg(t_mini *mini, t_token token)
{
	char	**command;
	int		i;

	if (!mini->command)
	{
		command = ft_calloc(3, sizeof(char *));
		command[0] = mini->c_line;
		command[1] = token.value;
	}
	else
	{
		command = ft_calloc(ft_nb_args(mini->command) + 2, sizeof(char *));
		i = 0;
		while (mini->command[i])
		{
			command[i] = mini->command[i];
			i++;
		}
		free(mini->command);
		command[i] = token.value;
	}
	return (command);
}
