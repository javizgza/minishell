/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:55:45 by carlos            #+#    #+#             */
/*   Updated: 2025/04/23 14:30:55 by cravegli         ###   ########.fr       */
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
	while (str[i] && str[i] != ' ' && str[i] != '\'')
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
	while (str[i] != ' ' && str[i] && str[i] != '\'')
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

char	*ft_dollar_found(char *str, char *res, t_mini *mini)
{
	char	*itoa_res;
	char	*aux;

	aux = ft_dollar_quote(str + 1);
	if (aux[0] && get_env_val(aux, mini->env))
		res = ft_add_var(res, get_env_val(aux, mini->env));
	else if (aux[0] && aux[0] == '?')
	{
		itoa_res = ft_itoa(mini->last_command);
		res = ft_add_var(res, itoa_res);
		free(itoa_res);
	}
	else
	{
		if (aux[0])
			res = ft_add_var(res, "");
	}
	free(aux);
	return (res);
}

char	*ft_has_dollar(char	*str, t_mini *mini)
{
	char	*res;
	int		single_quote;
	int		double_quote;
	int		i;

	res = str;
	single_quote = 1;
	double_quote = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && double_quote > 0)
			single_quote *= -1;
		if (str[i] == '\"' && single_quote > 0)
			double_quote *= -1;
		if (str[i] == '$' && single_quote > 0)
			res = ft_dollar_found(str + i, res, mini);
		i++;
	}
	if (!ft_is_equal(res, str))
		free(str);
	return (res);
}
