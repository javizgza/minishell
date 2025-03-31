/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:07:40 by marvin            #+#    #+#             */
/*   Updated: 2025/03/31 19:35:05 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

char	*ft_create_cmd(char **path, char *command)
{
	int		i;
	char	*s;
	char	*s2;

	i = 0;
	if (!access(command, F_OK | X_OK))
		return (command);
	if (!path || !path[0])
	{
		ft_error("NO PATH ERROR\n");
		return (NULL);
	}
	while (path[i])
	{
		s = ft_strjoin(path[i], "/");
		s2 = ft_strjoin(s, command);
		if (!access(s2, F_OK | X_OK))
			break ;
		i += 1;
		free(s);
		free(s2);
		s2 = NULL;
	}
	return (s2);
}

int	ft_execute_command(char **envp, char **arg)
{
	char	**path;
	char	*cmd;

	path = ft_split_path(envp);
	cmd = ft_create_cmd(path, arg[0]);
	if (!cmd)
	{
		if (path)
			ft_clean_array(path);
		ft_clean_array(arg);
		return (127);
	}
	execve(cmd, arg, envp);
	free(cmd);
	ft_clean_array(path);
	return (1);
}

int	ft_error_exe(int last_command, char *c_line, char **env)
{
	char	**path;

	path = ft_split_path(env);
	if (last_command == 127 && path)
	{
		ft_error(c_line);
		ft_error(": command not found\n");
	}
	if (last_command == 127 && !path)
	{
		ft_error(c_line);
		ft_error(": No such file or directory\n");
	}
	if (last_command == 1 && !ft_is_equal(c_line, "top"))
	{
		ft_error(c_line);
		ft_error(": Is a directory\n");
	}
	if (path)
		ft_clean_array(path);
	return (0);
}

int	ft_execute(t_mini *mini)
{
	pid_t	sub_process;

	sub_process = fork();
	if (!sub_process)
		exit(ft_execute_command(mini->env, mini->command));
	waitpid(sub_process, &mini->last_command, 0);
	mini->last_command /= 256;
	ft_error_exe(mini->last_command, mini->c_line, mini->env);
	return (1);
}

int	ft_execute_pipe(t_mini *mini)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	ft_execute_command(mini->env, mini->command);
	return (1);
}
