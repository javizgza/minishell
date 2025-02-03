/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rediret.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:17:15 by cravegli          #+#    #+#             */
/*   Updated: 2025/02/03 15:43:54 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_input_re(t_token *tokens)
{
	int	input;

	input = open(tokens->value, O_RDONLY, 0);
	if (input == -1)
		ft_error("open error\n");
	if (dup2(input, 0) == -1)
		ft_error("dup error\n");
	return (0);
}

int	ft_output_re(t_token *tokens)
{
	int		output;

	output = open(tokens->value, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (output == -1)
		ft_error("open error\n");
	if (dup2(output, 1) == -1)
		ft_error("dup error\n");
	return (0);
}

int	ft_output_re_t(t_token *tokens)
{
	int		output;

	output = open(tokens->value, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (dup2(output, 1) == -1)
		ft_error("dup error\n");
	return (0);
}

int	ft_mini_pipe(t_token *tokens, t_mini *mini)
{
	int		pip[2];
	pid_t	parent;

	if (pipe(pip) != 0)
		return (1);
	parent = fork();
	if (!parent)
	{
		if (dup2(pip[1], 1) == -1)
			return (1);
		close(pip[0]);
		return (ft_execute_command(tokens->value, mini->env));
	}
	waitpid(parent, 0, 0);
	if (dup2(pip[0], 0) == -1)
		return (1);
	return (0);
}
