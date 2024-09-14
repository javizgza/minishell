/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:10:54 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 16:24:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

char	**ft_split_path(char *envp[])
{
	int		i;
	char	**aux;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			break ;
		i += 1;
	}
	if (!envp[i])
		return (NULL);
	aux = ft_split(envp[i], '=');
	path = ft_split(aux[1], ':');
	ft_clean_array(aux);
	return (path);
}