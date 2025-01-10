/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierzaragozatejeda <javierzaragozatej    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:59:07 by codespace         #+#    #+#             */
/*   Updated: 2025/01/04 19:21:49 by javierzarag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_token *lexer(char *input)
{
    t_token *tokens;
    size_t token_count = 0;
    char *current_pos = input;

    tokens = malloc(sizeof(t_token) * 1024); // Allocate memory for tokens
    if (!tokens)
        return NULL;

    while (*current_pos)
    {
        t_token token = ft_define_token_struct(&current_pos);
        if (token.type != ERROR)
        {
            tokens[token_count++] = token;
        }
        else
        {
            fprintf(stderr, "Error: Invalid token\n");
            free(tokens);
            return NULL;
        }
    }
    tokens[token_count].type = END; // Mark the end of tokens
    return tokens;
}

