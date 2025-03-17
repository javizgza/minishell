/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:46:59 by cravegli          #+#    #+#             */
/*   Updated: 2025/03/17 20:47:26 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

char	*get_env_val(char *var, char **env)
{
	char	*value;
	int		i;

	i = 0;
	value = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
			value = ft_strchr(env[i], '=') + 1;
		i++;
	}
	return (value);
}

int	set_env_val(char *var, char **env)
{
	int		i;
	int		res;
	char	**aux;

	i = 0;
	aux = ft_split(var, '=');
	res = 1;
	while (env[i])
	{
		if (!ft_strncmp(env[i], aux[0], ft_strlen(aux[0])))
		{
			free(env[i]);
			env[i] = var;
			res = 0;
			break ;
		}
		i++;
	}
	ft_clean_array(aux);
	return (res);
}

char	**ft_add_env_val(char *var, char **env)
{
	int		i;
	char	**new_env;

	new_env = ft_calloc(sizeof(char *), ft_nb_args(env) + 2);
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		free(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(var);
	free(env);
	return (new_env);
}

char	**ft_del_env_val(char *var, char **env)
{
	int		i;
	int		y;
	char	**new_env;

	new_env = ft_calloc(sizeof(char *), ft_nb_args(env));
	i = 0;
	y = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)))
		{
			new_env[y] = ft_strdup(env[i]);
			y++;
		}
		free(env[i]);
		i++;
	}
	free(env);
	return (new_env);
}

void	ft_set_last_command(t_mini *mini, char *value)
{
	char	*var;

	var = ft_strjoin("_=", value);
	set_env_val(var, mini->env);
}
