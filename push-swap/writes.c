/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:18:50 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/13 16:36:35 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_ps(char ps, char c)
{
	write(1, &ps, 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	write_rotate(char c)
{
	write(1, "rr", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
