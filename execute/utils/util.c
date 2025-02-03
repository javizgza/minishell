/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:26:08 by cagonza2          #+#    #+#             */
/*   Updated: 2025/01/22 14:07:58 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_is_equal(char *a, char *b)
{
	int	i;

	i = 0;
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i ++;
	}
	return (1);
}

int	ft_nb_args(char **args)
{
	int		size;

	size = 0;
	while (args[size])
		size ++;
	return (size);
}

void	ft_clean_array(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i ++;
	}
	free(matrix);
}

void	ft_error(char *s)
{
	int	i;

	if (!ft_strncmp(s, "ERROR", 5))
		perror(s);
	else
	{
		i = 0;
		while (s[i])
		{
			write(2, &s[i], 1);
			i ++;
		}
		write(2, "\n", 1);
	}
	exit(2);
}

int	ft_load_env(t_mini *mini, char**env)
{
	int	i;

	mini->env = ft_calloc(sizeof(char *), ft_nb_args(env) + 1);
	if (!mini->env)
		return (0);
	i = 0;
	while (env[i])
	{
		mini->env[i] = ft_strdup(env[i]);
		if (!mini->env[i])
		{
			ft_clean_array(mini->env);
			return (0);
		}
		i++;
	}
	return (1);
}
