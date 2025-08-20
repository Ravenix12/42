/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:34:21 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/20 00:33:45 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_llist *lst, int both, char c)
{
	int	tempd;
	int tempi;
	
	if (lst->prev == NULL && lst->next == NULL)
		return ;
	if (lst && lst->next != NULL)
	{
		tempd = lst->next->data;
		tempi = lst->next->index;
		lst->next->data = lst->data;
		lst->next->index = lst->index;
		lst->data = tempd;
		lst->index = tempi;
	}
	else if (lst && lst->prev != NULL)
	{
		tempd = lst->prev->data;
		tempi = lst->prev->index;
		lst->prev->data = lst->data;
		lst->prev->index = lst->index;
		lst->data = tempd;
		lst->index = tempi;
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

t_llist*	extract_node_to_push(t_llist **stack)
{
	t_llist	*temp;

	temp = *stack;
	*stack = temp->next;
	if (*stack == NULL && temp->prev != NULL)
	{
		*stack = ft_llst_ht(temp, 'h');
		if (temp->prev != NULL)
			temp->prev->next = NULL;
	}
	else if (*stack == NULL && temp->prev == NULL)
		*stack = NULL;
	else if (*stack != NULL && temp->prev != NULL)
	{
		(*stack)->prev = temp->prev;
		temp->prev->next = (*stack)->prev;
	}
	else if (*stack != NULL && temp->prev == NULL)
		(*stack)->prev = NULL;
	return (temp) ;
}

// [push from 2 to 1]
void	push(t_llist **p_to, t_llist **p_from, char c)
{
	t_llist	*to_swap;
	t_llist	*temp;

	if (*p_from == NULL)
		return ;
	if (*p_to == NULL)
	{
		to_swap = extract_node_to_push(p_from);
		to_swap->next = NULL;
		to_swap->prev = NULL;
		*p_to = to_swap;
	}
	else
	{
		to_swap = extract_node_to_push(p_from);
		temp = (*p_to)->prev;
		(*p_to)->prev = to_swap;
		if (temp != NULL)
			temp->next = to_swap;
		to_swap->prev = temp;
		to_swap->next = *p_to;
		*p_to = to_swap;
	}
	write_ps('p', c);
	return ;
}

void	rotate(t_llist **stack_1, int dir, char c)
{
	t_llist *temp = *stack_1;

	if (!stack_1 || !*stack_1)
		return ;
	if (temp->prev == NULL && temp->next == NULL)
		return ;
	if (dir == 1 && temp->prev != NULL)
		*stack_1 = temp->prev;
	else if (dir == 1 && temp->prev == NULL)
		*stack_1 = ft_llst_ht(*stack_1, 't');
	else if (dir == 0 && temp->next != NULL)
		*stack_1 = temp->next;
	else if (dir == 0 && temp->next == NULL)
		*stack_1 = ft_llst_ht(*stack_1, 'h');
	write_rot(dir, c);
}
