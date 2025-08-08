/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:34:35 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/07 21:07:58 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_llist **lst)
{
	int	prev;

	if (!lst || !*lst)
		return (-1);
	while (*lst != NULL)
	{
		if ((*lst)->prev == NULL)
		{
			prev = (*lst)->data;
			*lst = (*lst)->next;
		}
		else
		{
			if ((*lst)->data > prev)
				*lst = (*lst)->next;
			else
				return (0);
		}
	}
	return (1);
}
void	string_input(char *argvi, t_llist **lst)
{
	char	**split_res;
	int		j;

	split_res = ft_split(argvi, ' ');
	j = 0;
	while (split_res[j] != NULL)
	{
		if (!is_valid(split_res[j], lst))		
		{
			write(1, "invalid input\n", 15);
			free_arr(split_res);
			exit(1);
		}
		add_node(lst, ft_atoi(split_res[j]));
		j++;
	}
	free_arr(split_res);
}

void	init_ll(char **argv, t_llist **lst)
{
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strchr(argv[i], ' ') != NULL)
			string_input(argv[i], lst);
		else
			add_node(lst, ft_atoi(argv[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_llist	*lst;

	lst = NULL;
	if (argc < 2 || !argv)
		return (1);
	else
	{
		init_ll(argv, &lst);
		if (!is_sorted(&lst))
		{
			//go into algo;
			printf("not sorted\n");
		}
	}
	return (0);
}
