/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:25:26 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 21:00:59 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_pwd(t_mini *mini)
{
	char	*aux;

	aux = getcwd(NULL, 0);
	printf("%s\n", aux);
	free(aux);
	mini->last_command = 1;
	return (1);
}
