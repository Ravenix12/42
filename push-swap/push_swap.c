/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:34:35 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/18 20:30:46 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_llist *lst)
{
	int	p;

	if (!lst)
		return (-1);
	while (lst != NULL)
	{
		if (lst->p == NULL)
		{
			p = lst->data;
			lst = lst->n;
		}
		else
		{
			if (lst->data > p)
			{
				p = lst->data;
				lst = lst->n;
			}
			else
				return (0);
		}
	}
	return (1);
}

void	multi_input(char *argvi, t_llist **lst)
{
	char	**split_res;
	int		j;
	int		check;

	split_res = ft_split(argvi, ' ');
	j = 0;
	check = 1;
	while (split_res[j] != NULL && check)
	{
		check = single_input(split_res[j], lst, 1);
		j++;
	}
	if (split_res[0] == NULL || split_res[0][0] == '\0' || !check)
	{
		{
			write(2, "Error\n", 6);
			free_arr(split_res);
			free_ll(*lst);
			exit(1);
		}
	}
	free_arr(split_res);
}

int	single_input(char *argvi, t_llist **lst, int m)
{
	if (!is_valid(argvi, lst) && !m)
	{
		write(2, "Error\n", 6);
		free_ll(*lst);
		exit(1);
	}
	if (!is_valid(argvi, lst) && m)
		return (0);
	add_node(lst, ft_atoi(argvi));
	return (1);
}

void	init_ll(char **argv, t_llist **lst)
{
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strchr(argv[i], ' ') != NULL)
			multi_input(argv[i], lst);
		else
			single_input(argv[i], lst, 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_llist	*lst;

	lst = NULL;
	if (argc == 1)
		return (0);
	else
	{
		init_ll(argv, &lst);
		if (!is_sorted(lst))
		{
			add_index(lst);
			entry_function(lst);
		}
		free_ll(ft_llst_ht(lst, 'h'));
	}
	return (0);
}
