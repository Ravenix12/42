/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:34:35 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/06 20:35:43 by smariapp         ###   ########.fr       */
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

void	free_arr(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*arr != NULL)
	{
		free(*arr);
		arr++;
	}
	free(tmp);
}

int	ft_isspace(char c)
{
	if ()
}

int	is_valid(char *hopefully_a_num, t_llist **lst)
{
	while(*hopefully_a_num != '\0')
	{
		if (!ft_isdigit(*hopefully_a_num) && !ft_isspace)
			return (0);
		
	}
}

void	init_ll(char **argv, t_llist **lst)
{
	int		i;
	char	**split_res;
	int		j;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strchr(argv[i], ' ') != NULL)
		{
			split_res = ft_split(argv[i], ' ');
			j = 0;
			while (split_res[j] != NULL)
			{
				add_node(lst, ft_atoi(split_res[j]));
				j++;
			}
			free_arr(split_res);
		}
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
// check if I can have multiple spaces inside string like "9     7 8 3"
}
