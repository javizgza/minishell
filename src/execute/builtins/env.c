/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:12:05 by marvin            #+#    #+#             */
/*   Updated: 2025/04/11 12:26:11 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

int	ft_env(t_mini *mini)
{
	int	i;

	i = 0;
	if (ft_nb_args(mini->command) > 1)
	{
		ft_error("env: too many arguments\n");
		mini->error = 1;
		return (1);
	}
	while (mini->env[i])
	{
		printf("%s\n", mini->env[i]);
		i++;
	}
	return (1);
}
