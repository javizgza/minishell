/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:41:49 by cravegli          #+#    #+#             */
/*   Updated: 2025/02/24 13:46:42 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_cd_aux(char *var, char *value, char **env)
{
	char	*res;

	res = ft_strjoin(var, value);
	if (set_env_val(res, env))
		free(res);
	return (1);
}

int	ft_cd_error(t_mini *mini, char *old_pwd)
{
	if (ft_nb_args(mini->command) > 2)
	{
		ft_error("cd: too many arguments\n");
		free(old_pwd);
		return (1);
	}
	if (!get_env_val("HOME", mini->env))
		ft_error("cd: HOME not set");
	if (ft_is_reg_file(mini->command[1]) == 0)
	{
		ft_error("cd: ");
		ft_error(mini->command[1]);
		ft_error(": Not a directory\n");
	}
	else
		printf("cd: %s: No such file or directory\n", mini->command[1]);
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
		return (ft_cd_error(mini, old_pwd));
	chdir(value);
	value = getcwd(NULL, 0);
	ft_cd_aux("PWD=", value, mini->env);
	free(value);
	ft_cd_aux("OLDPWD=", old_pwd, mini->env);
	free(old_pwd);
	return (1);
}
