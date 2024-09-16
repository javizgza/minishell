/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:38:08 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/16 16:33:02 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_lstsize(t_List *lst)
{
	int		i;
	t_List	*aux;

	aux = lst;
	i = 1;
	if (!aux)
		return (0);
	while (aux -> next)
	{
		aux = aux -> next;
		i += 1;
	}
	return (i);
}
