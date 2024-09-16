/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:40:08 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/16 16:33:02 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_List	*ft_lstnew(void *content)
{
	t_List	*list;

	list = malloc(sizeof(t_List));
	if (!list)
		return (NULL);
	list -> content = content;
	list -> next = NULL;
	return (list);
}
