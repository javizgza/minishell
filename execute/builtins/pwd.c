/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:25:26 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 17:59:21 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_pwd(t_List *env)
{
	t_Node	*node;
	char	**aux;

	node = env->first;
	while (node->next)
	{
		if (!ft_strncmp(node->element, "PWD", 3))
			break ;
		node = node->next;
	}
	if (!ft_strncmp(node->element, "PWD", 3))
	{
		aux = ft_split(node->element, '=');
		printf("%s\n", aux[1]);
		ft_clean_array(aux);
	}
	return (1);
}