/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:03:55 by codespace         #+#    #+#             */
/*   Updated: 2024/05/11 14:57:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

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


/* FUNCTIONS */
t_tokens    ft_define_tokens(char **token);
int ft_skip_white_spaces(char **str);

#endif