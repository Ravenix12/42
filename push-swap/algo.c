/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:03:42 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/14 20:15:46 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_4(t_llist **lsta, t_llist **lstb)
{
	int		i;
	t_llist	*temp;

	i = 0;
	temp = *lsta;
	while (temp && temp->ix != 0)
	{
		i++;
		temp = temp->n;
	}
	if (i == 1)
		swap(*lsta, 0, 'a');
	if (i == 2)
	{
		rotate(lsta, 1, 'a', 0);
		swap(*lsta, 0, 'a');
	}
	if (i == 3)
		rotate(lsta, -1, 'a', 0);
	push(lstb, lsta, 'b');
	sort_3(lsta, 3);
	push(lsta, lstb, 'a');
}

void	sort_5(t_llist **lsta, t_llist **lstb)
{
	int		i;
	t_llist	*temp;

	i = 0;
	temp = *lsta;
	while (temp && temp->ix != 4)
	{
		i++;
		temp = temp->n;
	}
	if (i == 1)
		swap(*lsta, 0, 'a');
	if (i == 2)
	{
		rotate(lsta, 1, 'a', 0);
		swap(*lsta, 0, 'a');
	}
	if (i == 3 || i == 4)
		rotate(lsta, -1, 'a', 0);
	if (i == 3)
		rotate(lsta, -1, 'a', 0);
	push(lstb, lsta, 'b');
	sort_4(lsta, lstb);
	push(lsta, lstb, 'a');
	rotate(lsta, 1, 'a', 0);
}

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
	else
		radix_sort(&stack_a, &stack_b, nodes);
}
