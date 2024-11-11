/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:46:59 by cravegli          #+#    #+#             */
/*   Updated: 2024/11/05 15:02:16 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

char	*get_env_val(char *var, t_list *env)
{
	char	*value;
	t_node	*node;

	node = env->first;
	value = NULL;
	while (node)
	{
		if (!ft_strncmp(node->element, var, ft_strlen(var)))
			value = ft_strchr(node->element, '=') + 1;
		node = node->next;
	}
	return (value);
}

int	set_env_val(char *var, t_list *env)
{
	t_node	*node;

	node = env->first;
	while (node)
	{
		if (!ft_strncmp(node->element, var, ft_strlen(var) - ft_strlen(ft_strchr(var, '='))))
			node->element = var;
		node = node->next;
	}
	return (0);
}
