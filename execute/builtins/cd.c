/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:41:49 by cravegli          #+#    #+#             */
/*   Updated: 2024/11/13 20:41:37 by cravegli         ###   ########.fr       */
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

int	ft_cd(t_mini *mini)
{
	char	*value;
	char	*old_pwd;

	if (get_env_val("PWD", mini->env))
		old_pwd = ft_strdup(get_env_val("PWD", mini->env));
	else
		old_pwd = getcwd(NULL, 0);
	if (ft_nb_args(mini->command) < 2)
	{
		value = get_env_val("HOME", mini->env);
		ft_cd_aux("PWD=", value, mini->env);
	}
	else if (access(mini->command[1], R_OK) == 0)
	{
		value = mini->command[1];
		chdir(value);
		value = getcwd(NULL, 0);
		ft_cd_aux("PWD=", value, mini->env);
		free(value);
	}
	else
		return (1);
	ft_cd_aux("OLDPWD=", old_pwd, mini->env);
	free(old_pwd);
	return (1);
}

