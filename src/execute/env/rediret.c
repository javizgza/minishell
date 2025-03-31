/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rediret.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:17:15 by cravegli          #+#    #+#             */
/*   Updated: 2025/03/31 19:41:40 by carlos           ###   ########.fr       */
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
		return (1);
	}
	if (dup2(mini->input, STDIN) == -1)
		ft_error("dup error\n");
	return (1);
}

int	ft_output_re(t_token tokens, t_mini *mini)
{
	if (mini->output > 0)
		close(mini->output);
	mini->output = open(tokens.value, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	dup2(mini->output, STDOUT);
	return (1);
}

int	ft_output_re_t(t_token tokens, t_mini *mini)
{
	if (mini->output > 0)
		close(mini->output);
	mini->output = open(tokens.value, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	dup2(mini->output, STDOUT);
	return (1);
}

int	ft_mini_pipe(t_mini *mini)
{
	int		pip[2];

	pipe(pip);
	mini->process[mini->pipe_done] = fork();
	if (!mini->process[mini->pipe_done])
	{
		dup2(pip[1], STDOUT);
		close(pip[0]);
		close(pip[1]);
		ft_shell(mini, 1);
		exit (1);
	}
	dup2(pip[0], mini->input);
	close(pip[0]);
	close(pip[1]);
	mini->pipe_done++;
	return (0);
}
