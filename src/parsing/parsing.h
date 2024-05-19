/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:03:55 by codespace         #+#    #+#             */
/*   Updated: 2024/05/19 16:35:02 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h> 
# include <stdlib.h>

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
	END,
	ERROR,
}  t_tokens;

typedef struct s_token
{
	t_tokens	type;
	char		*value;
}	t_token;

typedef struct s_commands
{
	char	*command;
	char	**args;
	int		args_num;
	char	input;
	char	output;
	char	output_append;
	char	input_delim;
}	t_commands;

/* FUNCTIONS */
void    ft_set_up_redir(t_commands *command, t_tokens type, char **token);
int	ft_strlen(char const *str);
char	*ft_strdup(const char *s);
t_tokens    ft_define_tokens(char **token);
int 		ft_skip_white_spaces(char **str);

#endif