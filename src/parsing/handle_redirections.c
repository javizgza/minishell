/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:01:47 by codespace         #+#    #+#             */
/*   Updated: 2024/05/19 16:34:27 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    parse_redir(char *input)
{
    char        *actual_pos;
    t_commands  *actual_command;
    t_tokens token_type;
    
    actual_pos = input;
    while (true)
    {
        token_type = ft_define_tokens(&actual_pos);
        if (token_type == END)
            break;
        else if (token_type == ERROR)
        {
            printf("Syntax Error.\n");
            break;
        }
        if (token_type == BIGGER || token_type == SMALLER ||
                token_type == BIGGERX2 || token_type == SMALLERX2)
                ft_set_up_redir(actual_command, token_type, &actual_pos);
    }
}

int main() {
    char input[] = "> >> < <<";  // Entrada simulada para redirecciones
    char *current_position = input;
    t_commands command = {0};

    // Llamada a la función de parseo (simulada aquí)
    while (true) {
        t_tokens token_type = ft_define_tokens(&current_position);
        if (token_type == END) {
            break;
        } else {
            ft_set_up_redir(&command, token_type, &current_position);
        }
    }

    // Imprimir resultados para verificar
    printf("Output file: %d\n", command.output);
    printf("Append file: %d\n", command.output_append);
    printf("Input file: %d\n", command.input);
    printf("Input delimiter file: %d\n", command.input_delim);

    // Limpieza (normalmente deberías también liberar la memoria asignada a los nombres de archivo
    return 0;
}