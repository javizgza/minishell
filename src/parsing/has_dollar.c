/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:55:45 by carlos            #+#    #+#             */
/*   Updated: 2025/03/11 14:52:16 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute/include/execute.h"

int	ft_var_result_len(char *str, char *add)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != '$')
		i++;
	while (str[i] && str[i] != ' ')
	{
		i++;
		len--;
	}
	len += ft_strlen(add);
	return (len + 1);
}

char	*ft_add_var_cont(char *str, char *res, int i, int new_len)
{
	while (str[i])
	{
		res[new_len] = str[i];
		i++;
		new_len++;
	}
	return (res);
}

char	*ft_add_var(char *str, char *add)
{
	char	*res;
	int		i;
	int		j;
	int		new_len;

	i = 0;
	j = 0;
	new_len = 0;
	res = ft_calloc(ft_var_result_len(str, add), sizeof(char));
	while (str[i] && str[i] != '$')
	{
		res[new_len] = str[i];
		i++;
		new_len++;
	}
	while (str[i] != ' ' && str[i])
		i++;
	while (add[j])
	{
		res[new_len] = add[j];
		j++;
		new_len++;
	}
	ft_add_var_cont(str, res, i, new_len);
	return (res);
}

char	*ft_has_dolar(char	*str, char **env, int last_command)
{
	char	*aux;
	char	*res;
	char	*itoa_res;
	int		single_quote;
	int		i;

	res = str;
	single_quote = 1;
	i = 0;
	aux = str;
	while (aux[i])
	{
		if (aux[i] == '\'')
			single_quote *= -1;
		if (aux[i] == '$')
		{
			i++;
			if (get_env_val(aux + i, env) && (single_quote > 0))
				res = ft_add_var(res, get_env_val(aux + i, env));
			else if (aux[i] == '?' && (single_quote > 0))
			{
				itoa_res = ft_itoa(last_command);
				res = ft_add_var(res, itoa_res);
				free(itoa_res);
			}
			else 
			{
				if (single_quote > 0)
					res = ft_add_var(res, "");
			}
		}
		//printf("res: %s\n", res);
		//printf("char: %c\n", aux[i]);
		i++;
	}
	if (!ft_is_equal(res, str))
		free(str);
	return (res);
}
