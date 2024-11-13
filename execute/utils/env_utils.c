/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:46:59 by cravegli          #+#    #+#             */
/*   Updated: 2024/11/13 12:50:38 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

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
	char	**aux;

	i = 0;
	aux = ft_split(var, '=');
	while (env[i])
	{
		if (!ft_strncmp(env[i], aux[0], ft_strlen(aux[0])))
		{
			free(env[i]);
			env[i] = var;
			break ;
		}
		i++;
	}
	ft_clean_array(aux);
	return (0);
}
