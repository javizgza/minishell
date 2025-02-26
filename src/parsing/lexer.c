/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:59:07 by codespace         #+#    #+#             */
/*   Updated: 2025/02/25 18:32:22 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t alloc_tokens(char *input)
{
    size_t count = 0;
    t_token token;
    char *actual_pos = input;

    while (*actual_pos)
    {
        token = ft_define_token_struct(&actual_pos);
		if (token.type != PIPE && token.type != ERROR)
			free (token.value);
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

    tokens = malloc(sizeof(t_token) * (alloc_tokens(input) + 1)); 
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
    return (tokens);
}

/* int main(void)
{
    char input[] = "echo hello | grep h > file.txt";
    t_token *tokens;
    
    tokens = lexer(input);
    if (!tokens)
    {
        fprintf(stderr, "Lexer returned NULL\n");
        return 1;
    }
    
    // Count detected tokens
    size_t token_count = 0;
    while (tokens[token_count].type != END)
    {
        printf("Token %zu: Type = %d, Value = %s\n", token_count, tokens[token_count].type, tokens[token_count].value);
        token_count++;
    }
    
    printf("Total tokens detected: %zu\n", token_count);
    
    free(tokens); // Free allocated memory
    return 0;
} */

