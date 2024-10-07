/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:08 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/16 17:58:35 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
# include "../../libft/libft.h"
# include "../list/list.h"

typedef struct env
{
    t_List *original_env;
    t_List *sort_env;
}   t_Env;

void	ft_clean_array(char **matrix);
void	ft_error(char *s);

char	*ft_create_cmd(char **path, char *command);
char	**ft_split_path(char *envp[]);

int		ft_is_equal(char *a, char *b);
int 	ft_echo(char **args);
int		ft_pwd(t_List *env);
int 	ft_nb_args(char **args);
int		ft_execute_command(char *command, char *envp[]);
int		ft_env(t_List *env);
int	    ft_load_env(t_List *l, char **env);
#endif