/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:01:47 by codespace         #+#    #+#             */
/*   Updated: 2024/05/11 17:09:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    parse_redir(char *input)
{
    char    *actual_pos;
    
    actual_pos = input;
    while (true)
    {
        t_tokens token;
        token = define_token(&actual_pos);
        
    }
}