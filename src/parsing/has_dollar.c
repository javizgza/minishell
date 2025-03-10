/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:55:45 by carlos            #+#    #+#             */
/*   Updated: 2025/03/10 11:42:18 by carlos           ###   ########.fr       */
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

	res = str;
	aux = ft_strchr(str, '$');
	while (aux)
	{
		aux++;
		if (get_env_val(aux, env))
			res = ft_add_var(res, get_env_val(aux, env));
		else if (*aux == '?')
		{
			itoa_res = ft_itoa(last_command);
			res = ft_add_var(res, itoa_res);
			free(itoa_res);
		}
		else
			res = ft_add_var(res, "");
		aux = ft_strchr(res, '$');
	}
	if (!ft_is_equal(res, str))
		free(str);
	return (res);
}
