/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:29:56 by cravegli          #+#    #+#             */
/*   Updated: 2024/11/05 14:23:39 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_exit(char **arg, t_list *env)
{
	if (ft_nb_args(arg) < 2)
	{
		rl_clear_history();
		ft_clean_array(arg);
		ft_delete_list(env);
		exit(115);
	}
	if (ft_nb_args(arg) == 2)
	{
		rl_clear_history();
		ft_clean_array(arg);
		ft_delete_list(env);
		exit(ft_atoi(arg[1]));
	}
	return (1);
}
