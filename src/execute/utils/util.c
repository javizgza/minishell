/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:25:46 by carlos            #+#    #+#             */
/*   Updated: 2025/04/03 11:23:11 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

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
		i++;
	}
	return (1);
}

int	ft_nb_args(char **args)
{
	int		size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

void	ft_clean_array(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
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
			write(STDERROR, &s[i], 1);
			i++;
		}
	}
}

int	ft_load_env(t_mini *mini, char**env)
{
	int	i;

	if (!env || !env[0])
		return (0);
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
