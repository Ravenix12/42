/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:03:42 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/20 22:15:58 by smariapp         ###   ########.fr       */
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
		sort_3(&stack_a, nodes);
	else if (nodes <= 5)
		sort_5(stack_a, stack_b, nodes);
		//sort_50(stack_a, stack_b, nodes);
	//print_ll(stack_b);
}

void	sort_3(t_llist **lst, int nodes)
{
	if (nodes == 2)
		swap(*lst, 0, 'a');
	else
	{
		if ((*lst)->ix > (*lst)->n->ix && (*lst)->n->ix > (*lst)->n->n->ix)
			swap(*lst, 0, 'a');
		if ((*lst)->ix < (*lst)->n->ix && (*lst)->ix > (*lst)->n->n->ix)
			rotate(lst, -1, 'a');
		if ((*lst)->n->ix < (*lst)->ix && (*lst)->ix < (*lst)->n->n->ix)
			swap(*lst, 0, 'a');
		if ((*lst)->ix < (*lst)->n->n->ix && (*lst)->n->ix > (*lst)->n->n->ix)
			swap(*lst, 0, 'a');
		if ((*lst)->ix > (*lst)->n->n->ix && (*lst)->n->ix < (*lst)->n->n->ix)
			rotate(lst, 1, 'a');
	}
	return ;
}

void	sort_5( t_llist *lsta, t_llist *lstb, int nodes)
{
	int		r;
	int		rr;
	t_llist	*tail;

	if (nodes == 4)
	{
		push(&lstb, &lsta, 'b');
		sort_3(&lsta, nodes);
		if (lstb->ix == 3)
		{
			push(&lsta, &lstb, 'a');
			swap(lsta, 0, 'a');
			return;
		}
		r = (lstb->ix - lsta->ix) * (lstb->ix - lsta->ix);
		tail = ft_llst_ht(lsta, 't');
		rr = (lstb->ix - tail->ix) * (lstb->ix - tail->ix);
		while (lsta->ix - lstb->ix != 1)
			{
				rotate(&lsta, (r < rr), 'a');
					printf("a: %d b: %d\n", lsta->ix, lstb->ix );
			}
		push(&lsta, &lstb, 'a');
		rotate(&lsta, lsta->ix >= nodes / 2, 'a');
	}
}
