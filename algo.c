/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:03:42 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/20 12:12:36 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	entry_function(t_llist *stack_a)
{
	int		nodes;
	t_llist	*stack_b;

	stack_b = NULL;
	nodes = count_nodes(stack_a);
	if (nodes <= 3)
		sort_3(stack_a, nodes);
	else if (nodes <= 50)
		return;
		//sort_50(stack_a, stack_b, nodes);
	print_ll(stack_b);
}

void	sort_3(t_llist *lst, int nodes)
{
	if (nodes == 2)
		swap(lst, 0, 'a');
	else
	{
		if (lst->index == 2 && lst->next->index == 1 && lst->next->next->index == 0)
			swap(lst, 0, 'a');
		if (lst->index == 1 && lst->next->index == 2 && lst->next->next->index == 0)
			rotate(&lst, 0, 'a');
		if (lst->index == 1 && lst->next->index == 0 && lst->next->next->index == 2)
			swap(lst, 0, 'a');
		if (lst->index == 0 && lst->next->index == 2 && lst->next->next->index == 1)
			swap(lst, 0, 'a');
		if (lst->index == 2 && lst->next->index == 0 && lst->next->next->index == 1)
			rotate(&lst, 1, 'a');
		// if (!is_sorted(lst))
		// 	printf("Edskjabefhj");
		TODO: rra fix
	}
	return;
}

// void	sort_50(t_llist *stack_a, t_llist *stack_b, int nodes)
// {
	
// }

