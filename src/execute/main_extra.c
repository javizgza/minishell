/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:00:50 by carlos            #+#    #+#             */
/*   Updated: 2025/03/17 20:44:08 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

char	*ft_level_up_shell(char **env)
{
	char	*value;
	char	*result;
	int		level;

	value = get_env_val("SHLVL", env);
	level = (ft_atoi(value) + 1);
	value = ft_itoa(level);
	result = ft_strjoin("SHLVL=", value);
	free (value);
	return (result);
}

void	ft_main_init(t_mini *mini, char **env)
{
	mini->in = dup(STDIN);
	mini->out = dup(STDOUT);
	mini->c_line = NULL;
	mini->command = NULL;
	mini->last_command = 0;
	mini->parent = -1;
	ft_set_signals();
	if (!ft_load_env(mini, env))
		ft_error("ERROR loading env");
	set_env_val(ft_level_up_shell(mini->env), mini->env);
}

void	ft_reset_mini(t_mini *mini)
{
	ft_reset_fd(mini);
	free(mini->command);
	if (mini->tokens)
		ft_free_tokens(mini->tokens);
	free(mini->line);
	mini->line = NULL;
	mini->c_line = NULL;
	mini->command = NULL;
}
