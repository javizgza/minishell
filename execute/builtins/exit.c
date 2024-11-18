/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:29:56 by cravegli          #+#    #+#             */
/*   Updated: 2024/11/18 12:16:53 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_exit(t_mini *mini)
{
	int	e;

	e = 0;
	//printf("salir\n");
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
