/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:44:50 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/14 20:17:15 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(int nodes)
{
	int	max_bits;

	max_bits = 0;
	while ((nodes - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

// nodes is total nodes, nodes_l is the nodes in that list
void	radix_sort(t_llist **lsta, t_llist **lstb, int nodes)
{
	int		i;
	int		nodes_l;

	i = -1;
	while (++i < max_bits(nodes))
	{
		nodes_l = count_nodes(*lsta);
		while (nodes_l--)
		{
			if ((((*lsta)->ix >> i) & 1) == 0)
				push(lstb, lsta, 'b');
			else
				rotate(lsta, 1, 'a', 0);
		}
		nodes_l = count_nodes(*lstb);
		while (nodes_l--)
		{
			if ((((*lstb)->ix >> (i + 1)) & 1) == 1)
				push(lsta, lstb, 'a');
			else
				rotate(lstb, 1, 'b', 0);
		}
	}
	while (*lstb)
		push(lsta, lstb, 'a');
}
