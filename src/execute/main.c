/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:15 by cagonza2          #+#    #+#             */
/*   Updated: 2025/02/26 12:47:56 by jazarago         ###   ########.fr       */
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
		dup2(mini->input, 0);
		dup2(mini->output, 1);
		return (1);
	}
	ft_clean_array(mini->command);
	dup2(mini->input, 0);
	dup2(mini->output, 1);
	return (1);
}

int	ft_check_redir(t_token *tokens, t_mini *mini)
{
	int	i;

	i = 0;
	dup2(0, mini->input);
	dup2(1, mini->output);
	while (tokens[i].type != END)
	{
		if (tokens[i].type == SMALLER)
			ft_input_re(tokens[i]);
		else if (tokens[i].type == SMALLERX2)
			ft_heredoc(mini, tokens[i]);
		else if (tokens[i].type == BIGGER)
			ft_output_re(tokens[i]);
		else if (tokens[i].type == BIGGERX2)
			ft_output_re_t(tokens[i]);
		else if (tokens[i].type == PIPE)
			ft_mini_pipe(mini);
		else if (tokens[i].type == COMMAND)
			mini->c_line = tokens[i].value;
		printf("value: %s, type: %i\n", tokens[i].value, tokens[i].type);
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
	if (!ft_load_env(&mini, envp))
		ft_error("ERROR loading env");
	while (1)
	{
		mini.line = readline("minishell> ");
		mini.tokens = lexer(mini.line);
		if (!ft_is_equal(mini.line, ""))
		{
			ft_check_redir(mini.tokens, &mini);
			add_history(mini.line);
		}
		ft_free_tokens(mini.tokens);
		free(mini.line);
		mini.line = NULL;
	}
	return (0);
}
