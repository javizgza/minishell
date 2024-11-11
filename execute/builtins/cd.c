/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:41:49 by cravegli          #+#    #+#             */
/*   Updated: 2024/11/05 14:42:11 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_cd_aux(char *var, char *value, t_list *env)
{
	char	*res;

	res = ft_strjoin(var, value);
	set_env_val(res, env);
	return (1);
}

int	ft_cd(char **arg, t_list *env)
{
	char	*value;
	char	*old_pwd;

	old_pwd = get_env_val("PWD", env);
	if (ft_nb_args(arg) < 2)
	{
		value = get_env_val("HOME", env);
		ft_cd_aux("PWD=", value, env);
	}
	if (access(arg[1], R_OK) == 0)
	{
		value = arg[1];
		chdir(value);
		value = ft_calloc(sizeof(char), 100);
		value = getcwd(value, 100);
		ft_cd_aux("PWD=", value, env);
		free(value);
	}
	else
		return (-1);
	ft_cd_aux("OLDPWD=", old_pwd, env);
	return (1);
}

