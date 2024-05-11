/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:22:55 by codespace         #+#    #+#             */
/*   Updated: 2024/05/11 16:35:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tokens    ft_define_tokens(char **token)
{
    while (ft_skip_white_spaces(token))
        (*token)++;
    if (**token == '\0')
        return (END);
    else if (**token == '|')
    {
        (*token)++;
        return (PIPE);
    }
    else if (**token == '>')
    {
        (*token)++;
        if (**token == '>')
        {
            (*token)++;
            return (BIGGERX2);
        }
        return (BIGGER);
    }
    else if (**token == '<')
    {
        (*token)++;
        if (**token == '<')
        {
            (*token)++;
            return (SMALLERX2);
        }
        return (SMALLER);
    }
    (*token)++;
    return (ERROR);
}

#include <stdio.h>

int main() {
    char input[] = "cat palab>>a.txt | wc -l | ls | wc -l >> out.txt";
    char *ptr = input;

    while (*ptr != '\0') {
        t_tokens token = ft_define_tokens(&ptr);
        switch (token) {
            case PIPE:
                printf("Token: PIPE\n");
                break;
            case BIGGER:
                printf("Token: BIGGER\n");
                break;
            case BIGGERX2:
                printf("Token: BIGGERX2\n");
                break;
            case SMALLER:
                printf("Token: SMALLER\n");
                break;
            case SMALLERX2:
                printf("Token: SMALLERX2\n");
                break;
            case END:
                printf("Token: END\n");
                break;
            case ERROR:
                printf("Token: ERROR\n");
                break;
            default:
                printf("Unknown token\n");
        }
    }
    return 0;
}
