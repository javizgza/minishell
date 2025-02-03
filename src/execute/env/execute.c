/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:07:40 by marvin            #+#    #+#             */
/*   Updated: 2025/02/03 15:50:43 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

char	*ft_create_cmd(char **path, char *command)
{
	int		i;
	char	*s;
	char	*s2;

	i = 0;
	if (!access(command, F_OK | X_OK))
		return (command);
	while (path[i])
	{
		s = ft_strjoin(path[i], "/");
		s2 = ft_strjoin(s, command);
		if (!access(s2, F_OK | X_OK))
			break ;
		i += 1;
		free(s);
		free(s2);
	}
	if (!path[i])
		return (NULL);
	free(s);
	return (s2);
}

int	ft_execute_command(char *command, char *envp[])
{
	char	**path;
	char	*cmd;
	char	**aux;

	path = ft_split_path(envp);
	if (!path)
		ft_error("NO PATH ERROR");
	aux = ft_split(command, ' ');
	cmd = ft_create_cmd(path, aux[0]);
	if (!cmd)
	{
		ft_clean_array(aux);
		ft_clean_array(path);
		return (127);
	}
	execve(cmd, aux, envp);
	free(cmd);
	ft_clean_array(path);
	ft_clean_array(aux);
	return (1);
}

int	ft_error_exe(int last_command, char *c_line)
{
	if (last_command == 127)
		printf("%s: command not found\n", c_line);
	return (0);
}

int	ft_check_redir(t_token *tokens, t_mini *mini)
{
	while (tokens)
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
			ft_mini_pipe(tokens, mini);
		tokens = tokens->next;
	}
	return (0);
}

int	ft_execute(t_mini *mini, char *line)
{
	pid_t	parent;

	parent = fork();
	if (!parent)
	{
		//ft_check_redir(mini->tokens, mini);
		exit(ft_execute_command(line, mini->env));
	}
	waitpid(parent, &mini->last_command, 0);
	mini->last_command /= 256;
	ft_error_exe(mini->last_command, mini->c_line);
	ft_clean_array(mini->command);
	return (1);
}
