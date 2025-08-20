/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:18:50 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/20 00:35:41 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_ps(char ps, char c)
{
	write(1, &ps, 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	write_rot(int dir, char c)
{
	if (!dir)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	else
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);	
	}
}
