/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:23:00 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/07 20:58:53 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"
# include "limits.h"

typedef struct s_llist
{
	struct s_llist	*prev;
	int				data;
	struct s_llist	*next;
	int				index;
}	t_llist;
//operations.c
void	swap(t_llist *lst);
void	swap_both(t_llist *stack_a, t_llist *stack_b);
void	push(t_llist *stack_1, t_llist *stack_2);
t_llist	*rotate(t_llist *stack_1, int dir);
//push-swap.c
int		is_sorted(t_llist **lst);
void	init_ll(char **argv, t_llist **lst);

//linkedlist.c
t_llist	*ft_llstlast(t_llist *lst);
void	add_node(t_llist **lst, int data);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	free_ll(t_llist *lst);
//kina_like_libft.c
int		ft_isspace(char c);
long	ft_atoi_long(const char *nptr);
void	free_arr(char **arr);
//validity
int		is_valid(char *num, t_llist **lst);
int 	valid_int(char *num, t_llist **lst);
int 	contains_non_digit(char *num, t_llist **lst);
int		check_dup(int num, t_llist *lst);
#endif
