/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:29:56 by cravegli          #+#    #+#             */
/*   Updated: 2024/11/13 13:15:02 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_exit(t_mini *mini)
{
	int	e;

	e = 0;
	if (ft_nb_args(mini->command) < 2)
	{
		rl_clear_history();
		ft_clean_array(mini->command);
		ft_clean_array(mini->env);
		exit(115);
	}
	if (ft_nb_args(mini->command) == 2)
	{
		e = ft_atoi(mini->command[1]);
		rl_clear_history();
		ft_clean_array(mini->command);
		ft_clean_array(mini->env);
		exit (e);
	}
	return (1);
}
