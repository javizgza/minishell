/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:29:09 by carlos            #+#    #+#             */
/*   Updated: 2025/04/23 13:55:28 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

t_signal	g_signal;

int	ft_is_builtins(t_mini *mini)
{
	if (ft_is_equal(mini->command[0], "echo"))
		return (ft_echo(mini->command));
	if (ft_is_equal(mini->command[0], "pwd"))
		return (ft_pwd());
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

int	ft_reset_fd(t_mini *mini)
{
	if (mini->input > 0)
		close(mini->input);
	if (mini->output > 0)
		close(mini->output);
	dup2(mini->in, STDIN);
	dup2(mini->out, STDOUT);
	return (1);
}

int	ft_shell(t_mini *mini, int pipe)
{
	if (!mini->c_line)
	{
		ft_exit_free(mini);
		return (0);
	}
	if (!mini->command)
	{
		mini->command = ft_calloc(2, sizeof(char *));
		mini->command[0] = mini->c_line;
	}
	ft_set_last_command(mini, mini->c_line);
	if (!ft_is_builtins(mini))
	{
		unset_signals();
		if (pipe == 0)
			ft_execute(mini);
		else
			return (ft_execute_pipe(mini));
		ft_reset_fd(mini);
		return (0);
	}
	ft_reset_fd(mini);
	return (0);
}

int	ft_check_redir(t_token *tokens, t_mini *mini)
{
	int	i;

	i = 0;
	while (tokens[i].type != END)
	{
		if (tokens[i].type == SMALLER)
			ft_input_re(tokens[i], mini);
		else if (tokens[i].type == SMALLERX2)
			ft_heredoc(mini, tokens[i]);
		else if (tokens[i].type == BIGGER)
			ft_output_re(tokens[i], mini);
		else if (tokens[i].type == BIGGERX2)
			ft_output_re_t(tokens[i], mini);
		else if (tokens[i].type == PIPE)
			ft_mini_pipe(mini);
		else if (tokens[i].type == COMMAND)
			mini->c_line = tokens[i].value;
		else if (tokens[i].type == ARGUMENT)
			mini->command = ft_add_arg(mini, tokens[i]);
		i++;
	}
	if (mini->error == 0)
		ft_shell(mini, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	(void) argc;
	(void) argv;
	ft_main_init(&mini, envp);
	while (1)
	{
		ft_set_signals();
		mini.line = readline("minishell> ");
		if (!mini.line)
			ft_exit_signal(&mini);
		if (mini.line)
		{
			mini.tokens = lexer(mini.line, &mini);
			if (mini.tokens && ft_parsing(&mini, mini.tokens))
			{
				ft_check_redir(mini.tokens, &mini);
				add_history(mini.line);
			}
		}
		if (mini.num_pipe > 0)
			ft_wait_pipes(&mini);
		ft_reset_mini(&mini);
	}
	return (0);
}
