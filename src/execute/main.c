/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:15 by cagonza2          #+#    #+#             */
/*   Updated: 2025/02/03 16:44:17 by cravegli         ###   ########.fr       */
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
		ft_execute(mini, mini->c_line);
		return (1);
	}
	ft_clean_array(mini->command);
	return (1);
}

int	ft_check_redir(t_token *tokens, t_mini *mini)
{
	while (tokens->type != END)
	{
		if (tokens->type == SMALLER)
			ft_input_re(tokens);
		else if (tokens->type == SMALLERX2)
			ft_heredoc(mini, tokens);
		else if (tokens->type == BIGGER)
			ft_output_re(tokens);
		else if (tokens->type == BIGGERX2)
			ft_output_re_t(tokens);
		else if (tokens->type == PIPE)
			ft_mini_pipe(mini);
		else if (tokens->type == COMMAND)
			mini->c_line = tokens->value;
		tokens = tokens->next;
	}
	ft_shell(mini);
	return (0);
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
			ft_check_redir(mini.tokens, &mini);
			add_history(mini.c_line);
		}
		free(mini.c_line);
	}
	return (0);
}
