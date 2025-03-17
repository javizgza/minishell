/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:55:45 by carlos            #+#    #+#             */
/*   Updated: 2025/03/17 20:48:20 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

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

char	*ft_dollar_found(char *str, char *res, t_mini *mini, int single_quote)
{
	char	*itoa_res;
	int		i;

	i = 1;
	if (str[i] && get_env_val(str + i, mini->env) && (single_quote > 0))
		res = ft_add_var(res, get_env_val(str + i, mini->env));
	else if (str[i] && str[i] == '?' && (single_quote > 0))
	{
		itoa_res = ft_itoa(mini->last_command);
		res = ft_add_var(res, itoa_res);
		free(itoa_res);
	}
	else
	{
		if (single_quote > 0 && str[i])
			res = ft_add_var(res, "");
	}
	return (res);
}

char	*ft_has_dollar(char	*str, t_mini *mini)
{
	char	*res;
	int		single_quote;
	int		i;

	res = str;
	single_quote = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			single_quote *= -1;
		if (str[i] == '$')
			res = ft_dollar_found(str + i, res, mini, single_quote);
		i++;
	}
	if (!ft_is_equal(res, str))
		free(str);
	return (res);
}
