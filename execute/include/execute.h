/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:08 by cagonza2          #+#    #+#             */
/*   Updated: 2025/01/22 13:56:52 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <termios.h>

typedef struct mini
{
	int		last_command;
	char	**env;
	char	**command;
	char	*c_line;
	char	**args;
	int		args_num;
	char	*input;
	char	*output;
	char	*output_append;
	char	*input_delim;
	char	*env_var;
	char	*pipes;
	char	*recent;
}	t_mini;

void	ft_clean_array(char **matrix);
void	ft_error(char *s);

char	*ft_create_cmd(char **path, char *command);
char	**ft_split_path(char *envp[]);

int		ft_is_equal(char *a, char *b);
int		ft_echo(char **args, t_mini *mini);
int		ft_pwd(t_mini *mini);
int		ft_exit(t_mini *mini);
int		ft_cd(t_mini *mini);
int		ft_export(t_mini *mini);
int		ft_nb_args(char **args);
int		ft_execute(t_mini *mini);
int		ft_env(t_mini *mini);
int		ft_unset(t_mini *mini);
int		ft_load_env(t_mini *mini, char**env);
char	*get_env_val(char *var, char **env);
int		set_env_val(char *var, char **env);
char	**ft_add_env_val(char	*var, char **env);
char	**ft_del_env_val(char *var, char **env);
int		ft_is_dir(char *file);
int		ft_is_reg_file(char *file);
#endif