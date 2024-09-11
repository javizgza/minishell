/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:15 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/11 17:49:31 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/execute.h"

int ft_shell(char *cLine)
{
	if (ft_is_equal(cLine, "echo"))
		return (ft_echo(cLine));
	return (1);
}

void  ft_free_all(char **args, int nb_chars)
{
	int	i;

	i = 0;
	while (i < nb_chars)
		free(args[i]);
	free(args);
}

int	main(void)
{
    char	*cLine;
    char	**csLine;
	int		i;

    cLine = readline("minishell> ");
	printf("\nComando: %s\n", cLine);
    ft_shell(csLine);
	free(cLine);
    return 0;
}
