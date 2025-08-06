/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:34:21 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/06 16:28:40 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_llist *lst)
{
	int	temp;

	if (lst && lst->next)
	{
		temp = lst->next->data;
		lst->next->data = lst->data;
		lst->data = temp;
	}
	return ;
}

void	swap_both(t_llist *stack_a, t_llist *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

// [push from 2 to 1]
void	push(t_llist *stack_1, t_llist *stack_2)
{
	t_llist	*to_swap;
	t_llist	*temp;

	to_swap = stack_2;
	temp = stack_2->next;
	temp->prev = to_swap->prev;
	to_swap->prev->next = temp;
	temp = stack_1->prev;
	temp->next = to_swap;
	to_swap->next = stack_1;
	to_swap->prev = temp;
	stack_1->prev = to_swap;
}

t_llist	*rotate(t_llist *stack_1, int dir)
{
	if (dir == 1 && stack_1 && stack_1->prev)
		return (stack_1->prev);
	else if ((dir == 0 && stack_1 && stack_1->next))
		return (stack_1->next);
	return (stack_1);
}
