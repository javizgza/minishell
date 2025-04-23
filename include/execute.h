/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:26:38 by carlos            #+#    #+#             */
/*   Updated: 2025/04/23 12:29:03 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <termios.h>
# include <signal.h>

# define STDIN 0
# define STDOUT 1
# define STDERROR 2

typedef enum s_tokens
{
	PIPE,
	BIGGER,
	SMALLER,
	BIGGERX2,
	SMALLERX2,
	COMMAND,
	ARGUMENT,
	END,
	ERROR,
}			t_tokens;

typedef struct s_token
{
	t_tokens			type;
	char				*value;
}				t_token;

typedef struct s_process
{
	pid_t	process;
	char	*command;
}				t_process;

typedef struct s_signal
{

	int	exit_sig;
	int	heredoc_fd;
}				t_signal;

typedef struct s_mini
{
	int			last_command;
	char		**env;
	char		**command;
	char		*c_line;
	char		*line;
	char		**args;
	int			input;
	int			output;
	int			in;
	int			out;
	int			error;
	int			num_pipe;
	int			pipe_done;
	t_process	*proc;
	t_token		*tokens;
}	t_mini;

void	ft_clean_array(char **matrix);
void	ft_error(char *s);

char	*ft_create_cmd(char **path, char *command);
char	**ft_split_path(char *envp[]);
char	**ft_find_env(void);

int		ft_is_equal(char *a, char *b);
int		ft_echo(char **args);
int		ft_pwd(void);
int		ft_exit(t_mini *mini);
int		ft_cd(t_mini *mini);
int		ft_export(t_mini *mini);
int		ft_nb_args(char **args);
int		ft_execute(t_mini *mini);
int		ft_env(t_mini *mini);
int		ft_unset(t_mini *mini);
void	ft_exit_signal(t_mini *mini);
int		ft_load_env(t_mini *mini, char**env);
char	*get_env_val(char *var, char **env);
int		set_env_val(char *var, char **env);
char	**ft_add_env_val(char	*var, char **env);
char	**ft_del_env_val(char *var, char **env);
int		ft_is_dir(char *file);
int		ft_is_reg_file(char *file);
int		ft_shell(t_mini *mini, int pipe);
void	ft_set_last_command(t_mini *mini, char *value);

int		ft_input_re(t_token token, t_mini *mini);
int		ft_output_re(t_token token, t_mini *mini);
int		ft_output_re_t(t_token token, t_mini *mini);
int		ft_heredoc(t_mini *mini, t_token token);
int		ft_error_exe(int last_command, char *c_line, char **env);

int		ft_execute_pipe(t_mini *mini);
int		ft_mini_pipe(t_mini *mini);
int		ft_is_num(char *num);
int		ft_reset_fd(t_mini *mini);

/* FUNCTIONS  PARSE*/
int		ft_parsing(t_mini *mini, t_token *tokens);
char	*ft_has_dollar(char	*str, t_mini *mini);
char	**ft_add_arg(t_mini *mini, t_token token);
t_token	*lexer(char *input, t_mini *mini);
t_token	*ft_re_lexer(char *input, t_mini *mini);
char	*ft_strndup(const char *s, size_t n);
t_token	ft_define_token_struct(char **token, int command_found);
int		ft_skip_white_spaces(char **str);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int		ft_white_spaces(char c);
void	ft_free_tokens(t_token *tokens);
char	*ft_substr_ignore_quotes(char *start, size_t len);
char	*ft_quote(char *start, size_t len);
void	ft_set_signals(void);
int		ft_parse_error(t_token token, int command_found);
void	unset_signals(void);

void	ft_main_init(t_mini *mini, char **env);
void	ft_reset_mini(t_mini *mini);
void	ft_wait_pipes(t_mini *mini);
void	ft_exit_free(t_mini *mini);

extern t_signal g_signal;
#endif