/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:08 by cagonza2          #+#    #+#             */
/*   Updated: 2024/11/13 12:52:23 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../../libft/libft.h"
# include "../list/list.h"

typedef struct mini
{
	int		last_command;
	char	**env;
	char	**command;
	char	*c_line;
}	t_mini;

void	ft_clean_array(char **matrix);
void	ft_error(char *s);

char	*ft_create_cmd(char **path, char *command);
char	**ft_split_path(char *envp[]);

int		ft_is_equal(char *a, char *b);
int		ft_echo(char **args, t_mini *mini);
int		ft_pwd(t_mini *mini);
int		ft_exit(char **arg, t_list *env);
int		ft_cd(t_mini *mini);
int		ft_export(char **arg, t_list *env);
int		ft_nb_args(char **args);
int		ft_execute_command(char *command, char *envp[]);
int		ft_env(t_List *env);
int		ft_load_env(t_mini *mini, char**env);
#endif