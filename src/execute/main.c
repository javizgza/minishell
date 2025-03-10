/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:15 by cagonza2          #+#    #+#             */
/*   Updated: 2025/03/10 12:39:37 by carlos           ###   ########.fr       */
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

int	ft_shell(t_mini *mini)
{
	if (!mini->c_line)
		return (0);
	mini->command = ft_split(mini->c_line, ' ');
	if (!ft_is_builtins(mini))
	{
		ft_execute(mini, mini->c_line);
		ft_reset_fd(mini);
		return (1);
	}
	ft_clean_array(mini->command);
	ft_reset_fd(mini);
	return (1);
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
		//printf("value: %s, type: %i\n", tokens[i].value, tokens[i].type);
		i++;
	}
	ft_shell(mini);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	(void) argc;
	(void) argv;
	mini.in = dup(STDIN);
	mini.out = dup(STDOUT);
	mini.c_line = NULL;
	if (!ft_load_env(&mini, envp))
		ft_error("ERROR loading env");
	while (1)
	{
		mini.line = readline("minishell> ");
		mini.tokens = lexer(mini.line);
		if (!mini.line)
			exit(mini.last_command);
		if (mini.line)
		{
			if (ft_parsing(&mini, mini.tokens))
				ft_check_redir(mini.tokens, &mini);
			add_history(mini.line);
		}
		ft_reset_fd(&mini);
		ft_free_tokens(mini.tokens);
		free(mini.line);
		mini.line = NULL;
		mini.c_line = NULL;
	}
	return (0);
}
