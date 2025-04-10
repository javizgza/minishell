/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:33:15 by cravegli          #+#    #+#             */
/*   Updated: 2025/04/03 12:26:06 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

int	ft_unset(t_mini *mini)
{
	int	i;

	i = 1;
	while (mini->command[i])
	{
		if (get_env_val(mini->command[i], mini->env))
			mini->env = ft_del_env_val(mini->command[i], mini->env);
		i++;
	}
	return (1);
}
