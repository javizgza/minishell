/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:26:08 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/16 17:48:02 by cagonza2         ###   ########.fr       */
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
		i += 1;
	}
	return (1);
}

int	ft_nb_args(char **args)
{
	int		size;

	size = 0;
	while (args[size])
		size += 1;
	return (size);
}

void	ft_clean_array(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i += 1;
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
			i += 1;
		}
		write(2, "\n", 1);
	}
	exit(1);
}

int	ft_load_env(t_List *l, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_add_node(l, env[i]))
			return (0);
		i += 1;
	}
	return (1);
}
