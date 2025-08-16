/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:34:21 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/14 18:22:35 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_llist *lst, int both, char c)
{
	int	temp;

	if (lst->prev == NULL && lst->next == NULL)
		return ;
	if (lst && lst->next != NULL)
	{
		temp = lst->next->data;
		lst->next->data = lst->data;
		lst->data = temp;
	}
	else if (lst && lst->prev != NULL)
	{
		temp = lst->prev->data;
		lst->prev->data = lst->data;
		lst->data = temp;
	}
	if (!both)
		write_ps('s', c);
}

void	swap_both(t_llist *stack_a, t_llist *stack_b)
{
	swap(stack_a, 1, 0);
	swap(stack_b, 1, 0);
	write_ps('s', 's');
}

// [push from 2 to 1]
void	push(t_llist **stack_1, t_llist **stack_2, char c)
{
	t_llist	*to_swap;
	t_llist	*temp;

	if (*stack_2 == NULL)
		return ;
	if (*stack_1 == NULL)
	{
		*stack_1 = *stack_2;
		temp = (*stack_2)->prev;
		if (temp != NULL)
			temp->next = (*stack_2)->next;
		if ((*stack_2)->next != NULL)
			(*stack_2)->next->prev = temp;
		(*stack_1)->next = NULL;
		(*stack_1)->prev = NULL; 
		return;
	}
	to_swap = *stack_2;
	temp = (*stack_2)->next;
	temp->prev = to_swap->prev;
	to_swap->prev->next = temp;
	temp = (*stack_1)->prev;
	temp->next = to_swap;
	to_swap->next = *stack_1;
	to_swap->prev = temp;
	(*stack_1)->prev = to_swap;
	write_ps('p', c);
}

t_llist	*rotate(t_llist *stack_1, int dir)
{
	if (stack_1 && stack_1->prev == NULL && stack_1->next == NULL)
		return (stack_1);
	if (dir == 1 && stack_1 && stack_1->prev != NULL)
		return (stack_1->prev);
	else if (dir == 1 && stack_1 && stack_1->prev == NULL)
		return (ft_llst_ht(stack_1, 't'));
	if ((dir == 0 && stack_1 && stack_1->next != NULL))
		return (stack_1->next);
	else if ((dir == 0 && stack_1 && stack_1->next == NULL))
		return (ft_llst_ht(stack_1, 'h'));
	printf("something is very wrong. checkkkkk"); //del later
	return (stack_1);
}
