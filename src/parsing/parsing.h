/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:03:55 by codespace         #+#    #+#             */
/*   Updated: 2025/03/13 14:48:18 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h> 
# include <stdlib.h>
# include "../../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef enum s_tokens
{
	PIPE,
	BIGGER,
	SMALLER,
	BIGGERX2,
	SMALLERX2,
	COMMAND,
	ARGUMENT,
	ENV_VAR,
	RECENT,
	FILENAME,
	END,
	ERROR,
}			t_tokens;

typedef struct s_token
{
	t_tokens			type;
	char				*value;
	struct s_token		*next;
}				t_token;

typedef struct s_commands
{
	char	*command;
	char	**args;
	int		args_num;
	char	*input;
	char	*output;
	char	*output_append;
	char	*input_delim;
	char	*env_var;
	char	*pipes;
	char	*recent;
}	t_commands;

/* FUNCTIONS */
void		ft_set_up_redir(t_commands *command, t_tokens type, char *token);
int			ft_strlen(char const *str);
char		*ft_strndup(const char *s, size_t n);
t_token		ft_define_token_struct(char **token, int command_found);
int			ft_skip_white_spaces(char **str);
void		execute_commands(t_commands *command);
char		*ft_strncpy(char *dest, const char *src, size_t n);
int			ft_white_spaces(char c);
void		ft_free_tokens(t_token *tokens);
char		*ft_substr_ignore_quotes(char *start, size_t len);
char		*ft_quote(char *start, size_t len);
void		ft_set_signals(void);
int			ft_parse_error(t_token token, int command_found);
void		unset_signals(void);

#endif