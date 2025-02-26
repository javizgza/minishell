/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:35:36 by jazarago          #+#    #+#             */
/*   Updated: 2025/02/26 13:40:55 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_handle_env_var(t_commands *command, char *token)
{
	char	*env_value;

	env_value = getenv(token);
	if (env_value)
		command->env_var = ft_strndup(env_value, ft_strlen(env_value));
	else
		command->env_var = ft_strndup(token, ft_strlen(token));
}

void	ft_set_up_redir(t_commands *command, t_tokens type, char *token)
{
	size_t	n;

	n = ft_strlen(token);
	if (type == ENV_VAR)
		ft_handle_env_var(command, token);
	else if (type == BIGGER)
		command->output = ft_strndup(token, n);
	else if (type == BIGGERX2)
		command->output_append = ft_strndup(token, n);
	else if (type == SMALLER)
		command->input = ft_strndup(token, n);
	else if (type == SMALLERX2)
		command->input_delim = ft_strndup(token, n);
	else if (type == PIPE)
		command->pipes = ft_strndup(token, n);
	else if (type == COMMAND || type == ARGUMENT)
	{
		if (!command->command)
			command->command = ft_strndup(token, n);
		else
			command->args[command->args_num++] = ft_strndup(token, n);
	}
}
