/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:27:00 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/14 18:22:11 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*ft_llst_ht(t_llist *lst, char ht)
{
	if (ht == 'h')
	{
		while (lst && lst->prev)
		{
			lst = lst->prev;
		}
		return (lst);
	}
	else if (ht == 't')
	{
		while (lst && lst->next)
		{
			lst = lst-> next;
		}
		return (lst);
	}
	return (NULL);
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
		new->index = -1;
		new->next = NULL;
		return ;
	}
	new->prev = ft_llst_ht(*lst, 't');
	new->data = data;
	new->index = -1;
	new->next = NULL;
	ft_llst_ht(*lst, 't')->next = new;
}

void	free_ll(t_llist *lst)
{
	t_llist	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

int	count_nodes(t_llist *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	print_ll(t_llist *lst)//remove
{
	while (lst != NULL)
	{
		printf("data: %d\n", lst->data);
		printf("index: %d\n", lst->index);
		lst = lst->next;
	}
}
