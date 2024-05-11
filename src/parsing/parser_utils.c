/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:26:18 by codespace         #+#    #+#             */
/*   Updated: 2024/05/11 14:57:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int ft_white_spaces(char c)
{
    return ((c == ' ') || (c >= 9 && c<= 15));
}

int ft_skip_white_spaces(char **token)
{
    int j;
    int i;

    i = 0;
    j = 0;
    while (ft_white_spaces(token[i][j]))
        j++;
    return (j);
}
