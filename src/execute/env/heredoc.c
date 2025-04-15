/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:55:21 by cravegli          #+#    #+#             */
/*   Updated: 2025/04/15 14:39:01 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

void	ft_dollar_heredoc(char *line, t_mini *mini, int infile)
{
	char	*aux;

	aux = get_env_val(line + 1, mini->env);
	if (aux)
	{
		ft_putstr_fd(aux, infile);
		return ;
	}
	line++;
	if (line && (*line == '0' || *line == '?'))
	{
		if (*line == '0')
			ft_putstr_fd("minishell", infile);
		if (*line == '?')
			ft_putnbr_fd(mini->last_command, infile);
	}
}

int	ft_print_heredoc(char *line, t_mini *mini, int infile)
{
	int		i;
	char	**split_line;
	char	*aux;

	i = 0;
	split_line = ft_split(line, ' ');
	while (split_line[i])
	{
		aux = ft_strchr(split_line[i], '$');
		if (aux)
			ft_dollar_heredoc(aux, mini, infile);
		else
			ft_putstr_fd(split_line[i], infile);
		if (split_line[i + 1])
			ft_putchar_fd(' ', infile);
		i++;
	}
	ft_putchar_fd('\n', infile);
	ft_clean_array(split_line);
	return (0);
}

int	ft_child_heredoc(int infile, char *del, t_mini *mini)
{
	char	*line;

	while (1)
	{
		line = readline(">");
		if (ft_is_equal(line, del) || !line)
			break ;
		ft_print_heredoc(line, mini, infile);
		free(line);
	}
	if (line)
		free(line);
	close(infile);
	return (0);
}

int	ft_parent_heredoc(int heredoc[2], pid_t parent, t_mini *mini)
{
	waitpid(parent, 0, 0);
	mini->input = heredoc[0];
	dup2(mini->input, STDIN);
	close(heredoc[1]);
	close(heredoc[0]);
	return (0);
}

int	ft_heredoc(t_mini *mini, t_token tokens)
{
	int		heredoc[2];
	pid_t	parent;

	if (mini->input > 0)
	{
		close(mini->input);
		dup2(mini->in, STDIN);
	}
	pipe(heredoc);
	g_signal.heredoc_fd = heredoc[1];
	parent = fork();
	if (!parent)
	{
		close(heredoc[0]);
		exit (ft_child_heredoc(heredoc[1], tokens.value, mini));
	}
	else
		ft_parent_heredoc(heredoc, parent, mini);
	return (0);
}
