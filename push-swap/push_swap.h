/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:23:00 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/06 17:43:20 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"

typedef struct s_llist
{
	struct s_llist	*prev;
	int				data;
	struct s_llist	*next;
	int				index;
}	t_llist;

void	swap(t_llist *lst);
void	swap_both(t_llist *stack_a, t_llist *stack_b);
void	push(t_llist *stack_1, t_llist *stack_2);
t_llist	*rotate(t_llist *stack_1, int dir);

int		is_sorted(t_llist **lst);
void	free_arr(char **arr);
void	add_node(t_llist **lst, int data);
void	init_ll(char **argv, t_llist **lst);

t_llist	*ft_llstlast(t_llist *lst);

#endif
