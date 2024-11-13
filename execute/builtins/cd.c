/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:41:49 by cravegli          #+#    #+#             */
/*   Updated: 2024/11/13 13:02:18 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_cd_aux(char *var, char *value, char **env)
{
	char	*res;

	res = ft_strjoin(var, value);
	set_env_val(res, env);
	return (1);
}

int	ft_cd(t_mini *mini)
{
	char	*value;
	char	*old_pwd;

	old_pwd = get_env_val("PWD", mini->env);
	if (ft_nb_args(arg) < 2)
	{
		value = get_env_val("HOME", mini->env);
		ft_cd_aux("PWD=", value, mini->env);
	}
	else if (access(arg[1], R_OK) == 0)
	{
		value = arg[1];
		chdir(value);
		//value = ft_calloc(sizeof(char), 100);
		value = getcwd(NULL, 0);
		ft_cd_aux("PWD=", value, mini->env);
		free(value);
	}
	else
	{
		mini->last_command = -1;
		return (1);
	}
	ft_cd_aux("OLDPWD=", old_pwd, mini->env);
	mini->last_command = 1;
	return (1);
}

