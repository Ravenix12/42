/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:23:00 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/20 00:38:01 by shivani          ###   ########.fr       */
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
void	swap(t_llist *lst, int both, char c);
void	swap_both(t_llist *stack_a, t_llist *stack_b);
t_llist*	extract_node_to_push(t_llist **stack_2);
void	push(t_llist **stack_1, t_llist **stack_2, char c);
void	rotate(t_llist **stack_1, int dir, char c);
//push-swap.c
int		is_sorted(t_llist *lst);
void	init_ll(char **argv, t_llist **lst);
void	multi_input(char *argvi, t_llist **lst);
void	single_input(char *argvi, t_llist **lst);
//linkedlist.c
t_llist	*ft_llst_ht(t_llist *lst, char ht);
int		count_nodes(t_llist *lst);
void	add_node(t_llist **lst, int data);
void	free_ll(t_llist *lst);


void	print_ll(t_llist *lst);



//kina_like_libft.c
int		ft_isspace_or_sign(char c);
long	ft_atoi_long(const char *nptr);
void	free_arr(char **arr);
//validity
int		is_valid(char *num, t_llist **lst);
int		valid_int(char *num, t_llist **lst);
int		contains_non_digit(char *num, t_llist **lst);
int		check_dup(int num, t_llist *lst);
int		zero_check(char *num);
//writes
void	write_ps(char ps, char c);
void	write_rot(int dir, char c);
//indexing
void	sort_arr(int *arr, int len);
void	indexing(t_llist *lst, int *arr, int nodes);
void	add_index(t_llist *lst);

//algo
void	entry_function(t_llist *stack_a);
void	sort_3(t_llist *stack_a, int nodes);

#endif
