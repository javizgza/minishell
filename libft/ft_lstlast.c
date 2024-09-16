/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:48:25 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/16 16:33:02 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_List	*ft_lstlast(t_List *lst)
{
	t_List	*aux;

	aux = lst;
	if (!aux)
		return (aux);
	while (aux -> next)
		aux = aux -> next;
	return (aux);
}
