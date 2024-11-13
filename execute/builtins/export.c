/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:53:54 by cravegli          #+#    #+#             */
/*   Updated: 2024/11/13 13:09:54 by carlos           ###   ########.fr       */
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

int	ft_export(t_mini *mini)
{
	char	**vars;
	char	*value;

	if (ft_nb_args(mini->command) < 2)
	{
		mini->last_command = 1;
		return (ft_print_env(mini->env));
	}
	if (ft_strchr(mini->command[1], '='))
	{
		vars = ft_split(mini->command[1], '=');
		value = get_env_val(vars[0], mini->env);
		if (!value)
		{
			ft_clean_array(vars);
			mini->last_command = 1;
			return (0);
		}
		set_env_val(mini->command[1], mini->env);
		ft_clean_array(vars);
	}
	mini->last_command = 1;
	return (1);
}
