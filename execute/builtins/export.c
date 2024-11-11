/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:53:54 by cravegli          #+#    #+#             */
/*   Updated: 2024/11/05 14:50:01 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_print_env(t_list *env)
{
	t_node	*node;
	int		i;

	node = env->first;
	while (node)
	{
		i = 0;
		printf("declare -x ");
		while (node->element[i] != '=')
		{
			printf("%c", node->element[i]);
			i++;
		}
		printf("%c", node->element[i]);
		i++;
		printf("%c", 34);
		while (node->element[i])
		{
			printf("%c", node->element[i]);
			i++;
		}
		printf("%c\n", 34);
		node = node->next;
	}
	return (1);
}

int	ft_export(char **arg, t_list *env)
{
	char	**vars;
	char	*value;

	if (ft_nb_args(arg) < 2)
		return (ft_print_env(env));
	if (ft_strchr(arg[1], '='))
	{
		vars = ft_split(arg[1], '=');
		value = get_env_val(vars[0], env);
		if (!value)
		{
			ft_clean_array(vars);
			return (ft_add_node(env, arg[1]));
		}
		set_env_val(arg[1], env);
		ft_clean_array(vars);
	}
	return (1);
}
