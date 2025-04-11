/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:53:54 by cravegli          #+#    #+#             */
/*   Updated: 2025/04/11 12:27:55 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

char	**ft_print_help_env(char *str, char **env)
{
	int		i;
	char	**split_res;

	i = 0;
	split_res = ft_split(str, '=');
	while (str[i] != '=')
	{
		printf("%c", str[i]);
		i++;
	}
	printf("%c", str[i]);
	i++;
	printf("%c", 34);
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
	printf("%c\n", 34);
	env = ft_del_env_val(split_res[0], env);
	ft_clean_array(split_res);
	return (env);
}

int	ft_next_print(char **env)
{
	int	i;
	int	res;

	i = 0;
	res = i;
	while (env[i])
	{
		if (ft_strncmp(env[i], env[res], ft_strlen(env[i])) < 0)
			res = i;
		i++;
	}
	return (res);
}

void	ft_print_env(char	**env)
{
	int		i;
	int		print;
	char	**temp_env;

	i = 0;
	temp_env = ft_calloc(ft_nb_args(env) + 1, sizeof(char *));
	while (env[i])
	{
		temp_env[i] = ft_strdup(env[i]);
		i++;
	}
	while (ft_nb_args(temp_env) > 0)
	{
		printf("declare -x ");
		print = ft_next_print(temp_env);
		if (ft_strchr(temp_env[print], '='))
			temp_env = ft_print_help_env(temp_env[print], temp_env);
		else
		{
			printf("%s\n", temp_env[print]);
			temp_env = ft_del_env_val(temp_env[print], temp_env);
		}
	}
	free(temp_env);
}

int	ft_export_cont(t_mini *mini)
{
	char	**vars;
	int		i;

	i = 1;
	while (i < ft_nb_args(mini->command))
	{
		if (ft_strchr(mini->command[i], '='))
		{
			vars = ft_split(mini->command[i], '=');
			if (!get_env_val(vars[0], mini->env))
				mini->env = ft_add_env_val(mini->command[i], mini->env);
			else
				set_env_val(ft_strdup(mini->command[i]), mini->env);
			ft_clean_array(vars);
		}
		else
		{
			if (!get_env_val(mini->command[i], mini->env))
				mini->env = ft_add_env_val(mini->command[i], mini->env);
			else
				set_env_val(ft_strdup(mini->command[i]), mini->env);
		}
		i++;
	}
	return (1);
}

int	ft_export(t_mini *mini)
{
	if (ft_nb_args(mini->command) < 2)
	{
		ft_print_env(mini->env);
		return (1);
	}
	return (ft_export_cont(mini));
}
