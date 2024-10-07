/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:15 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/16 17:58:42 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/execute.h"

int	ft_is_builtins(char **cLine, t_List *env)
{
	if (ft_is_equal(cLine[0], "echo"))
		return (ft_echo(cLine));
	if (ft_is_equal(cLine[0], "pwd"))
		return (ft_pwd(env));
	if (ft_is_equal(cLine[0], "env"))
		return (ft_env(env));
	return (0);
}

int ft_shell(char **cLine, int number_commands, char **envp)
{
	t_Env env;

	env.original_env = ft_create_list();
	if (!ft_load_env(env.original_env, envp))
		return (0);
	(void)number_commands;
	if (!ft_is_builtins(cLine, env.original_env))
		return (ft_execute_command(cLine[0], envp));
	ft_delete_list(env.original_env);
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

int	main(int argc, char **argv, char **envp)
{
    char	*cLine;

	(void) argc;
	(void) argv;
    while (1)
	{
		cLine = readline("minishell> ");
		printf("\nComando: %s\n", cLine);
    	char *csLine[]  = {"pwd", "echo", "-n", "\0", "que tal estas \n salto de línea", "*pues muy bien¡, por?", NULL};
		if (!ft_shell(csLine, 2, envp))
			return (0);
		free(cLine);	
	}	
    return 0;
}
