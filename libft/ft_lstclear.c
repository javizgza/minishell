/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:20:18 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/16 16:33:02 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_List **lst, void (*del)(void*))
{
	t_List	*aux;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		aux = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = NULL;
}
