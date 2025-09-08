/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:36:11 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/20 20:23:31 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	indexing(t_llist *lst, int *arr, int nodes)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (i < nodes)
		{
			if (arr[i] == lst->data)
			{
				lst->ix = i;
				break ;
			}
			i++;
		}
		lst = lst->n;
	}
}

void	add_index(t_llist *lst)
{
	int		nodes;
	int		*arr;
	int		i;
	t_llist	*head;

	head = lst;
	nodes = count_nodes(lst);
	arr = (int *)malloc(nodes * sizeof(int));
	i = 0;
	while (lst != NULL)
	{
		arr[i] = lst->data;
		i++;
		lst = lst->n;
	}
	sort_arr(arr, nodes);
	indexing(head, arr, nodes);
	free(arr);
}
