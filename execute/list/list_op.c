/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:20:52 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/16 17:36:39 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void	ft_del_last_node(t_List *l)
{
	t_Node	*aux;

	if (l->size  == 0)
		return ;
	aux = l->first;
	if (l->size > 1)
	{
		while (aux->next)
			aux = aux->next;
		aux->pre->next = NULL;
		l->last = aux->pre;
		aux->pre = NULL;
	}
	free(aux);
}

void	ft_del_first_node(t_List *l)
{
	l->first->next->pre = NULL;
	l->first = l->first->next;
}

int	ft_add_node(t_List *l, char *element)
{
	t_Node	*node;
	t_Node	*aux;
	
	node = ft_create_node(element, l->size);
	if (l->size == 0)
	{
		l->first = node;
		l->last = node;
	}
	else
	{
		aux = l->first;
		while (aux->next)
			aux = aux->next;
		aux->next = node;
		node->pre = aux;
	}
	l->size += 1;
	return (1);
}

void	ft_list_string(t_List *l)
{
	t_Node	*node;
	
	if (l->size == 0)
		printf("Empty list.");
	else
	{
		node = l->first;
		printf("List Size: %d; Content: ", l->size);
		if (l->size > 1)
		{
			while (node->next)
			{
				printf("%s ", node->element);
				node = node->next;
			}
		}
		printf("%s ;", node->element);
	}
}
