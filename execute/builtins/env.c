/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:12:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/18 12:38:53 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_env(t_mini *mini)
{
	int	i;

	i = 0;
	if (ft_nb_args(mini->command) > 1)
	{
		printf("env: too many arguments\n");
		mini->last_command = 2;
		return (1);
	}
	while (mini->env[i])
	{
		printf("%s\n", mini->env[i]);
		i++;
	}
	mini->last_command = 0;
	return (1);
}
