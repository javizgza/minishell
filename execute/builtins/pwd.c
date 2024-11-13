/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:25:26 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 12:25:53 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_pwd(t_mini *mini)
{
	int		i;
	char	**aux;

	i = 0;
	while (mini->env[i])
	{
		if (!ft_strncmp(mini->env[i], "PWD", 3))
			break ;
		i++;
	}
	if (!ft_strncmp(mini->env[i], "PWD", 3))
	{
		aux = ft_split(mini->env[i], '=');
		printf("%s\n", aux[1]);
		ft_clean_array(aux);
	}
	mini->last_command = 1;
	return (1);
}
