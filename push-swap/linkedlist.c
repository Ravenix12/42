/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:27:00 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/20 20:22:49 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*ft_llst_ht(t_llist *lst, char ht)
{
	if (ht == 'h')
	{
		while (lst && lst->p)
			lst = lst->p;
		return (lst);
	}
	else if (ht == 't')
	{
		while (lst && lst->n != NULL)
			lst = lst-> n;
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
		new->p = NULL;
		new->data = data;
		new->ix = -1;
		new->n = NULL;
		return ;
	}
	new->p = ft_llst_ht(*lst, 't');
	new->data = data;
	new->ix = -1;
	new->n = NULL;
	ft_llst_ht(*lst, 't')->n = new;
}

void	free_ll(t_llist *lst)
{
	t_llist	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->n;
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
		lst = lst->n;
	}
	return (i);
}

void	print_ll(t_llist *lst)//remove
{
	while (lst != NULL)
	{
		printf("data: %d\n", lst->data);
		printf("index: %d\n", lst->ix);
		lst = lst->n;
	}
}
