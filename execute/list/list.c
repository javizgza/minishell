/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:17:09 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/16 16:40:53 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

t_List	*ft_create_list(void)
{
	t_List	*new_list;

	new_list = (t_List *)malloc(sizeof(t_List));
	if (!new_list)
		return (NULL);
	new_list->first = NULL;
	new_list->last = NULL;
	new_list->size = 0;
	return (new_list);
}

void	ft_delete_list(t_List *l)
{
	if (l->size == 0)
		free(l);
	return ;
	while (l->last)
		ft_del_last_node(l);
	free(l);
}

t_Node	*ft_create_node(char *new_element, int position)
{
	t_Node	*node;

	node = (t_Node *)malloc(sizeof(t_Node));
	if (!node)
		return (NULL);
	node->element = new_element;
	node->position = position;
	node->next = NULL;
	node->pre = NULL;
	return (node);
}
