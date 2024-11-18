/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:15 by cagonza2          #+#    #+#             */
/*   Updated: 2024/11/18 12:42:49 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/execute.h"

int	ft_is_builtins(t_mini *mini)
{
	if (ft_is_equal(mini->command[0], "echo"))
		return (ft_echo(mini->command, mini));
	if (ft_is_equal(mini->command[0], "pwd"))
		return (ft_pwd(mini));
	if (ft_is_equal(mini->command[0], "env"))
		return (ft_env(mini));
	if (ft_is_equal(mini->command[0], "exit"))
		return (ft_exit(mini));
	if (ft_is_equal(mini->command[0], "cd"))
		return (ft_cd(mini));
	if (ft_is_equal(mini->command[0], "export"))
		return (ft_export(mini));
	if (ft_is_equal(mini->command[0], "unset"))
		return (ft_unset(mini));
	return (0);
}

int	ft_shell(t_mini *mini)
{
	mini->command = ft_split(mini->c_line, ' ');
	if (!ft_is_builtins(mini))
	{
		ft_clean_array(mini->command);
		ft_execute(mini);
		return (1);
	}
	ft_clean_array(mini->command);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	(void) argc;
	(void) argv;
	if (!ft_load_env(&mini, envp))
		ft_error("ERROR loading env");
	while (1)
	{
		mini.c_line = readline("minishell> ");
		if (!ft_is_equal(mini.c_line, ""))
		{
			if (!ft_shell(&mini))
				return (0);
			add_history(mini.c_line);
		}
		free(mini.c_line);
	}
	return (0);
}
