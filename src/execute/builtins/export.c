/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:53:54 by cravegli          #+#    #+#             */
/*   Updated: 2024/11/18 14:08:26 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_print_env(char	**env)
{
	int	i;
	int	y;

	y = 0;
	while (env[y])
	{
		i = 0;
		printf("declare -x ");
		while (env[y][i] != '=')
		{
			printf("%c", env[y][i]);
			i++;
		}
		printf("%c", env[y][i]);
		i++;
		printf("%c", 34);
		while (env[y][i])
		{
			printf("%c", env[y][i]);
			i++;
		}
		printf("%c\n", 34);
		y++;
	}
	return (1);
}

int	ft_export_cont(t_mini *mini)
{
	char	**vars;
	char	*value;
	int		i;

	i = 0;
	while (i < ft_nb_args(mini->command))
	{
		if (ft_strchr(mini->command[i], '='))
		{
			vars = ft_split(mini->command[i], '=');
			value = get_env_val(vars[0], mini->env);
			if (!value)
				mini->env = ft_add_env_val(mini->command[i], mini->env);
			else
				set_env_val(ft_strdup(mini->command[i]), mini->env);
			ft_clean_array(vars);
		}
		i++;
	}
	return (1);
}

int	ft_export(t_mini *mini)
{
	if (ft_nb_args(mini->command) < 2)
	{
		mini->last_command = 0;
		return (ft_print_env(mini->env));
	}
	mini->last_command = 0;
	return (ft_export_cont(mini));
}
