/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:03:42 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/14 18:21:56 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	entry_function(t_llist *stack_a)
{
	//int		nodes;
	t_llist	*stack_b;

	stack_b = NULL;
	//nodes = count_nodes(stack_a);
	push(&stack_b, &stack_a, 'b');
	push(&stack_b, &stack_a, 'b');
	print_ll(stack_b);
}
