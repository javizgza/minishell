/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:41:37 by cravegli          #+#    #+#             */
/*   Updated: 2025/04/03 12:47:09 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/execute.h"

char	**ft_find_env(void)
{
	char	**result;
	int		fd_path;
	char	*path;

	fd_path = open("/etc/environment", O_RDONLY, 0);
	if (!fd_path)
		return (NULL);
	path = get_next_line(fd_path);
	close (fd_path);
	result = ft_calloc(2, sizeof(char *));
	result[0] = path;
	return (result);
}
