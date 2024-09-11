/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:08 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/11 15:59:35 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
# include "../../libft/libft.h"

int	ft_is_equal(char *a, char *b);
int ft_echo(char **args);

#endif