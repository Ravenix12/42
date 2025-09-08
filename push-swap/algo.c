/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:03:42 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/21 19:52:42 by smariapp         ###   ########.fr       */
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
	else if (nodes == 4)
		sort_4(&stack_a, &stack_b);
	else if (nodes == 5)
		sort_5(&stack_a, &stack_b);
		//sort_50(stack_a, stack_b, nodes);
	//print_ll(stack_b);
}

void	sort_3(t_llist **lst, int nodes)
{
	if (nodes == 2 && !is_sorted(*lst))
		swap(*lst, 0, 'a');
	else if (nodes == 3)
	{
		if ((*lst)->ix > (*lst)->n->ix && (*lst)->n->ix > (*lst)->n->n->ix)
			swap(*lst, 0, 'a');
		if ((*lst)->ix < (*lst)->n->ix && (*lst)->ix > (*lst)->n->n->ix)
			rotate(lst, -1, 'a', 0);
		if ((*lst)->n->ix < (*lst)->ix && (*lst)->ix < (*lst)->n->n->ix)
			swap(*lst, 0, 'a');
		if ((*lst)->ix < (*lst)->n->n->ix && (*lst)->n->ix > (*lst)->n->n->ix)
			swap(*lst, 0, 'a');
		if ((*lst)->ix > (*lst)->n->n->ix && (*lst)->n->ix < (*lst)->n->n->ix)
			rotate(lst, 1, 'a', 0);
	}
	return ;
}

void	helper(t_llist **lsta, t_llist **lstb)
{
	int		r;
	int		rr;
	t_llist	*tail;

	r = ((*lstb)->ix - (*lsta)->ix) * ((*lstb)->ix - (*lsta)->ix);
	tail = ft_llst_ht(*lsta, 't');
	rr = ((*lstb)->ix - tail->ix) * ((*lstb)->ix - tail->ix);
	while (((*lsta)->ix - (*lstb)->ix != 1))
		rotate(lsta, (r < rr), 'a', 0);
	push(lsta, lstb, 'a');
}

void	sort_4(t_llist **lsta, t_llist **lstb)
{
	push(lstb, lsta, 'b');
	sort_3(lsta, 3);
	if ((*lstb)->ix == 3)
	{
		push(lsta, lstb, 'a');
		rotate(lsta, 1, 'a', 0);
		return ;
	}
	helper(lsta, lstb);
	while (!is_sorted(*lsta))
		rotate(lsta, (*lsta)->ix >= 2, 'a', 0);
	print_ll(*lsta);
}

void	sort_5( t_llist **lsta, t_llist **lstb)
{
	push(lstb, lsta, 'b');
	push(lstb, lsta, 'b');
	sort_3(lsta, 3);
	if (is_sorted(*lstb))
		swap(*lstb, 0, 'b');
	if ((*lstb)->ix == 4)
		push(lsta, lstb, 'a');
	else
		helper(lsta, lstb);
	helper(lsta, lstb);
	while (!is_sorted(*lsta))
	rotate(lsta, (*lsta)->ix >= 2, 'a', 0);
	print_ll(*lsta);
}
