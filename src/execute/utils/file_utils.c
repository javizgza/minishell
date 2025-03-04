/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:34:04 by cravegli          #+#    #+#             */
/*   Updated: 2025/03/04 11:54:52 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	ft_is_dir(char *file)
{
	struct stat	stat_file;

	stat(file, &stat_file);
	if (S_ISDIR(stat_file.st_mode))
		return (0);
	return (1);
}

int	ft_is_reg_file(char *file)
{
	struct stat	stat_file;

	stat(file, &stat_file);
	if (S_ISREG(stat_file.st_mode))
		return (0);
	return (1);
}

int	ft_is_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}
