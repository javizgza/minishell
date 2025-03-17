/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:41:49 by cravegli          #+#    #+#             */
/*   Updated: 2025/03/17 20:49:39 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

int	ft_cd_aux(char *var, char *value, char **env)
{
	char	*res;

	res = ft_strjoin(var, value);
	if (set_env_val(res, env))
		free(res);
	return (1);
}

int	ft_cd_error(t_mini *mini, char *old_pwd, char *value)
{
	ft_error("cd: ");
	if (ft_nb_args(mini->command) > 2)
	{
		ft_error("too many arguments\n");
		free(old_pwd);
		return (1);
	}
	if (!get_env_val("HOME", mini->env))
		ft_error("HOME not set");
	ft_error(value);
	if (ft_is_reg_file(value) == 0)
		ft_error(": Not a directory\n");
	else
		ft_error(": No such file or directory\n");
	free(old_pwd);
	mini->last_command = 1;
	return (1);
}

int	ft_cd_not_access(t_mini *mini, char *value, char *old_pwd)
{
	if (access(value, X_OK) != 0)
	{
		ft_error("permission denied: ");
		ft_error(value);
		ft_error("\n");
	}
	mini->last_command = 1;
	free(old_pwd);
	return (1);
}

int	ft_cd(t_mini *mini)
{
	char		*value;
	char		*old_pwd;

	if (get_env_val("PWD", mini->env))
		old_pwd = ft_strdup(get_env_val("PWD", mini->env));
	else
		old_pwd = getcwd(NULL, 0);
	if (ft_nb_args(mini->command) < 2 && get_env_val("HOME", mini->env))
		value = get_env_val("HOME", mini->env);
	else if (ft_is_dir(mini->command[1]) == 0)
		value = mini->command[1];
	else
		return (ft_cd_error(mini, old_pwd, mini->command[1]));
	if (access(value, X_OK) != 0)
		return (ft_cd_not_access(mini, value, old_pwd));
	chdir(value);
	value = getcwd(NULL, 0);
	ft_cd_aux("PWD=", value, mini->env);
	free(value);
	ft_cd_aux("OLDPWD=", old_pwd, mini->env);
	free(old_pwd);
	mini->last_command = 0;
	return (1);
}
