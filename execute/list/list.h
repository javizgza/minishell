/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <cagonza2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:14:11 by cagonza2          #+#    #+#             */
/*   Updated: 2024/09/16 16:44:00 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
	char        *element;
	int			position;
	struct node	*next;
	struct node	*pre;
}	t_Node;

typedef struct stack
{
	t_Node	*first;
	t_Node	*last;
	int		size;
}	t_List;


t_List	*ft_create_list(void);
void	ft_delete_list(t_List *l);

t_Node	*ft_create_node(char *new_element, int position);

void	ft_del_last_node(t_List *l);
void	ft_del_first_node(t_List *l);
int	    ft_add_node(t_List *l, char *element);
void	ft_list_string(t_List *l);
#endif
