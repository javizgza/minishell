/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierzaragozatejeda <javierzaragozatej    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:59:07 by codespace         #+#    #+#             */
/*   Updated: 2025/02/03 12:12:49 by javierzarag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t  alloc_tokens(char *input)
{
    size_t count;
    t_token token;
    char *current_pos;

    count = 0;
    current_pos = input;

    while (*current_pos)
    {
        token = ft_define_token_struct(&current_pos);
        if (token.type != ERROR)
            count++;
    }
    return (count);
}

t_token *lexer(char *input)
{
    t_token *tokens;
    size_t token_count = 0;
    char *current_pos = input;

    tokens = malloc(sizeof(t_token) * alloc_tokens(input)); // Allocate memory for tokens
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

