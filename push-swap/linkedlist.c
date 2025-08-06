/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:27:00 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/06 18:16:52 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*ft_llstlast(t_llist *lst)
{
	while (lst && lst->next)
	{
		lst = lst-> next;
	}
	return (lst);
}

void	add_node(t_llist **lst, int data)
{
	t_llist	*new;

	if (!lst)
		return ;
	new = (t_llist *)malloc(sizeof(t_llist));
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
		new->data = data;
		new->next = NULL;
		return ;
	}
	ft_llstlast(*lst)->next = new;
	new->prev = *lst;
	new->data = data;
}