/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:08 by cagonza2          #+#    #+#             */
/*   Updated: 2025/03/04 14:21:29 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../../parsing/parsing.h"
# include "../../../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <termios.h>

# define STDIN 0
# define STDOUT 1
# define STDERROR 2

typedef struct mini
{
	int		last_command;
	char	**env;
	char	**command;
	char	*c_line;
	char	*line;
	char	**args;
	int		args_num;
	int		input;
	int		output;
	int		in;
	int		out;
	char	*output_append;
	char	*input_delim;
	char	*env_var;
	char	*pipes;
	char	*recent;
	int		pipe[2];
	t_token	*tokens;
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
int		ft_execute(t_mini *mini, char *line);
int		ft_env(t_mini *mini);
int		ft_unset(t_mini *mini);
int		ft_load_env(t_mini *mini, char**env);
char	*get_env_val(char *var, char **env);
int		set_env_val(char *var, char **env);
char	**ft_add_env_val(char	*var, char **env);
char	**ft_del_env_val(char *var, char **env);
int		ft_is_dir(char *file);
int		ft_is_reg_file(char *file);
int		ft_shell(t_mini *mini);

int		ft_input_re(t_token token, t_mini *mini);
int		ft_output_re(t_token token, t_mini *mini);
int		ft_output_re_t(t_token token, t_mini *mini);
int		ft_heredoc(t_mini *mini, t_token token);
int		ft_execute_command(char *command, char *envp[]);
int		ft_mini_pipe(t_mini *mini);
int		ft_is_num(char *num);
int		ft_reset_fd(t_mini *mini);

#endif