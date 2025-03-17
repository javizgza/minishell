/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:29:56 by cravegli          #+#    #+#             */
/*   Updated: 2025/03/17 20:51:39 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

void	ft_exit_free(t_mini *mini)
{
	rl_clear_history();
	free(mini->command);
	ft_free_tokens(mini->tokens);
	ft_clean_array(mini->env);
	free(mini->line);
}

void	ft_exit_signal(t_mini *mini)
{
	rl_clear_history();
	exit(mini->last_command);
}

int	ft_error_exit(char **command, t_mini *mini)
{
	if (ft_is_num(command[1]))
	{
		ft_reset_fd(mini);
		printf("exit\n");
		ft_error("exit: ");
		ft_error(command[1]);
		ft_error(": numeric argument required\n");
		ft_exit_free(mini);
		exit (2);
	}
	else if (ft_nb_args(command) > 2)
	{
		ft_error("exit: too many arguments\n");
		return (1);
	}
	return (0);
}

int	ft_exit(t_mini *mini)
{
	int	e;

	e = 0;
	if (ft_nb_args(mini->command) >= 2 && ft_error_exit(mini->command, mini))
		return (1);
	if (ft_nb_args(mini->command) < 2)
	{
		ft_exit_free(mini);
		ft_reset_fd(mini);
		printf("exit\n");
		exit(mini->last_command);
	}
	if (ft_nb_args(mini->command) >= 2)
	{
		e = ft_atoi(mini->command[1]);
		ft_exit_free(mini);
		ft_reset_fd(mini);
		printf("exit\n");
		exit (e);
	}
	return (1);
}
