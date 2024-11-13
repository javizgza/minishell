/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:07:40 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 21:07:58 by cravegli         ###   ########.fr       */
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
		return (0);
	}
	execve(cmd, aux, envp);
	free(cmd);
	ft_clean_array(path);
	ft_clean_array(aux);
	return (1);
}

int	ft_execute(t_mini *mini)
{
	pid_t	parent;

	parent = fork();
	if (!parent)
		ft_execute_command(mini->c_line, mini->env);
	if (parent)
		waitpid(parent, &mini->last_command, 0);
	return (1);
}
