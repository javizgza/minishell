/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:41:37 by cravegli          #+#    #+#             */
/*   Updated: 2025/04/23 14:59:44 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

char	*ft_fix_path(char *path)
{
	char	*result;
	int		i;

	result = ft_calloc(ft_strlen(path), sizeof(char));
	i = 0;
	while (path[i] != '\n')
	{
		result[i] = path[i];
		i++;
	}
	free(path);
	return (result);
}

char	**ft_find_env(void)
{
	int		fd_path;
	char	*path;
	char	**result;
	char	*pwd;
	char	*aux_pwd;

	fd_path = open("/etc/environment", O_RDONLY, 0);
	result = NULL;
	if (fd_path)
	{
		path = get_next_line(fd_path);
		path = ft_fix_path(path);
		close (fd_path);
		result = ft_add_env_val(path, result);
	}
	pwd = getcwd(NULL, 0);
	aux_pwd = ft_strjoin("PWD=", pwd);
	free(pwd);
	result = ft_add_env_val(aux_pwd, result);
	return (result);
}
