/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:12:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 17:50:05 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_env(t_List *env)
{
	t_Node	*aux;

	aux = env->first;
	while (aux->next)
	{
		printf("%s\n", aux->element);
		aux = aux->next;
	}
	printf("%s\n", aux->element);
	return (1);
}