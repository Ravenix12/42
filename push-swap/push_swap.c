/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:34:35 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/21 15:04:37 by smariapp         ###   ########.fr       */
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

	if (ft_strncmp(argvi, "", 1) == 0)
		return ;
	split_res = ft_split(argvi, ' ');
	j = 0;
	while (split_res[j] != NULL)
	{
		if (!is_valid(split_res[j], lst))
		{
			write(2, "Error\n", 7);
			free_arr(split_res);
			free_ll(*lst);
			exit(1);
		}
		add_node(lst, ft_atoi(split_res[j]));
		j++;
	}
	free_arr(split_res);
}

void	single_input(char *argvi, t_llist **lst)
{
	if (ft_strncmp(argvi, "", 1) == 0)
		return ;
	if (!is_valid(argvi, lst))
	{
		write(2, "Error\n", 7);
		free_ll(*lst);
		exit(1);
	}
	add_node(lst, ft_atoi(argvi));
}

void	init_ll(char **argv, t_llist **lst)
{
	int		i;

	i = 1;
	while (argv[i] != NULL && *argv[i] != '\0')
	{
		if (ft_strchr(argv[i], ' ') != NULL)
			multi_input(argv[i], lst);
		else
			single_input(argv[i], lst);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_llist	*lst;

	lst = NULL;
	if (argc < 2 || !argv)
		return ((int)write(2, "Error\n", 7));
	else
	{
		init_ll(argv, &lst);
		printf("Successfully exited init\n"); //remove
		if (!is_sorted(lst))
		{
			add_index(lst);
			entry_function(lst);
		}
		free_ll(lst);
	}
	return (0);
}
