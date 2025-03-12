/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:00:50 by carlos            #+#    #+#             */
/*   Updated: 2025/03/12 17:05:58 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/execute.h"

void	ft_main_init(t_mini *mini, char **env)
{
	mini->in = dup(STDIN);
	mini->out = dup(STDOUT);
	mini->c_line = NULL;
	mini->command = NULL;
	ft_set_signals();
	if (!ft_load_env(mini, env))
		ft_error("ERROR loading env");
}

void	ft_reset_mini(t_mini *mini)
{
	ft_reset_fd(mini);
	ft_free_tokens(mini->tokens);
	free(mini->line);
	mini->line = NULL;
	mini->c_line = NULL;
	mini->command = NULL;
}
