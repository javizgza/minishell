/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:25:26 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 16:39:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_pwd(char **env)
{
	int		i;
	char	**aux;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PWD", 3))
			break ;
		i += 1;
	}
	if (!env[i])
		return (0);
	aux = ft_split(env[i], '=');
	printf("%s\n", aux[1]);
	ft_clean_array(aux);
	return (1);
}