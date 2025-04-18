/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rediret.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:17:15 by cravegli          #+#    #+#             */
/*   Updated: 2025/04/10 11:56:11 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

int	ft_input_re(t_token tokens, t_mini *mini)
{
	if (mini->input > 0)
		close(mini->input);
	mini->input = open(tokens.value, O_RDONLY, 0);
	if (mini->input == -1)
	{
		ft_error("bash: ");
		ft_error(tokens.value);
		ft_error(": No such file or directory\n");
		mini->error = 2;
		return (1);
	}
	dup2(mini->input, STDIN);
	return (1);
}

int	ft_output_re(t_token tokens, t_mini *mini)
{
	if (mini->output > 0)
		close(mini->output);
	mini->output = open(tokens.value, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (mini->output == -1)
	{
		ft_error("bash: ");
		ft_error(tokens.value);
		ft_error(": No such file or directory\n");
		mini->error = 2;
		return (1);
	}
	dup2(mini->output, STDOUT);
	return (1);
}

int	ft_output_re_t(t_token tokens, t_mini *mini)
{
	if (mini->output > 0)
		close(mini->output);
	mini->output = open(tokens.value, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (mini->output == -1)
	{
		ft_error("bash: ");
		ft_error(tokens.value);
		ft_error(": No such file or directory\n");
		mini->error = 2;
		return (1);
	}
	dup2(mini->output, STDOUT);
	return (1);
}

int	ft_mini_pipe(t_mini *mini)
{
	int		pip[2];

	pipe(pip);
	mini->proc[mini->pipe_done].command = mini->c_line;
	mini->proc[mini->pipe_done].process = fork();
	if (!mini->proc[mini->pipe_done].process)
	{
		dup2(pip[1], STDOUT);
		close(pip[0]);
		close(pip[1]);
		if (mini->error == 0)
			ft_shell(mini, 1);
		exit (mini->error);
	}
	dup2(pip[0], STDIN);
	close(pip[0]);
	close(pip[1]);
	mini->pipe_done++;
	free(mini->command);
	mini->command = NULL;
	mini->error = 0;
	if (mini->output > 0)
		close(mini->output);
	dup2(mini->out, STDOUT);
	return (0);
}
