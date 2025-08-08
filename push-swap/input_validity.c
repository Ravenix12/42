/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:13:25 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/07 21:09:08 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(int num, t_llist *lst)
{
	t_llist	*head;

	head = lst;
	while (lst != NULL)
	{
		if (lst->data == num)
		{
			free_ll(head);
			return (0);
		}
		else
			lst = lst->next;
	}
	return (1);
}

int contains_non_digit(char *num, t_llist **lst)
{
	int	i;

	i = 0;
	while (num[i] != '\0')
	{
		if (!ft_isdigit(num[i]) && !ft_isspace(num[i]) && num[i] != '-' && num[i] != '+')
		{
			free_ll(*lst);
			return (0);
		}
		i++;
	}
	return (1);
}

int valid_int(char *num, t_llist **lst)
{
	long	i;

	if (ft_strncmp("0", num, 1) == 0)
		return (0);
	i = ft_atoi_long(num);
	if (i == 0 || (i < INT_MIN && i > INT_MAX))
	{
		free_ll(*lst);
		return (0);
	}
	else if (!check_dup(i, *lst))
	{
		free_ll(*lst);
		return (0);
	}
	return (1);
}

int	is_valid(char *num, t_llist **lst)
{
	if (!contains_non_digit(num, lst) || !valid_int(num, lst))
		return (0);
	return (1);
}