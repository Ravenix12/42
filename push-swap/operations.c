/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:34:21 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/21 15:06:34 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_llist *lst, int both, char c)
{
	int	tempd;
	int	tempi;

	if (lst->p == NULL && lst->n == NULL)
		return ;
	if (lst && lst->n != NULL)
	{
		tempd = lst->n->data;
		tempi = lst->n->ix;
		lst->n->data = lst->data;
		lst->n->ix = lst->ix;
		lst->data = tempd;
		lst->ix = tempi;
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

t_llist	*extract_node_to_push(t_llist **stack)
{
	t_llist	*temp;

	temp = *stack;
	*stack = temp->n;
	if (*stack == NULL && temp->p != NULL)
	{
		*stack = ft_llst_ht(temp, 'h');
		if (temp->p != NULL)
			temp->p->n = NULL;
	}
	else if (*stack == NULL && temp->p == NULL)
		*stack = NULL;
	else if (*stack != NULL && temp->p != NULL)
	{
		(*stack)->p = temp->p;
		temp->p->n = (*stack)->p;
	}
	else if (*stack != NULL && temp->p == NULL)
		(*stack)->p = NULL;
	return (temp);
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
		to_swap->n = NULL;
		to_swap->p = NULL;
		*p_to = to_swap;
	}
	else
	{
		to_swap = extract_node_to_push(p_from);
		temp = (*p_to)->p;
		(*p_to)->p = to_swap;
		if (temp != NULL)
			temp->n = to_swap;
		to_swap->p = temp;
		to_swap->n = *p_to;
		*p_to = to_swap;
	}
	write_ps('p', c);
	return ;
}

void	rotate_no_space(t_llist **stack, int dir)
{
	t_llist	*temp;
	t_llist	*lst;

	lst = *stack;
	if (dir >= 1)
	{
		temp = ft_llst_ht(lst, 't');
		temp->n = lst;
		lst->n->p = NULL;
		lst->n = NULL;
		lst->p = temp;
		*stack = ft_llst_ht(lst, 'h');
	}
	else if (dir <= 0)
	{
		temp = ft_llst_ht(lst, 't');
		temp->p->n = NULL;
		lst->p = temp;
		temp->n = lst;
		temp->p = NULL;
		*stack = ft_llst_ht(lst, 'h');
	}
}

// 1:ra -1:rra
void	rotate(t_llist **stack, int dir, char c, int both)
{
	int		nodes;
	t_llist	*lst;

	lst = *stack;
	nodes = count_nodes(ft_llst_ht(lst, 'h'));
	if (!lst || nodes <= 1)
		return ;
	if (nodes == 2)
	{
		swap(lst, 0, c);
		return ;
	}
	rotate_no_space(stack, dir);
	if (!both)
		write_rot(dir, c);
}

void	rotate_both(t_llist **stack_a, t_llist **stack_b, int dir)
{
	rotate(stack_a, dir, 'a', 1);
	rotate(stack_b, dir, 'a', 1);
	write_rot(dir, 'r');
}
