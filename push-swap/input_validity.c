/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:13:25 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/18 20:31:32 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	zero_check(char *num)
{
	if (ft_strncmp("0", num, 2) == 0)
		return (1);
	else if (ft_strncmp("+0", num, 3) == 0 || ft_strncmp("-0", num, 3) == 0)
		return (1);
	else if (ft_strncmp("+", num, 2) == 0 || ft_strncmp("-", num, 2) == 0)
		return (0);
	else if (*num == '+' || *num == '-' || *num == '0')
	{
		num++;
		while (*num != '\0')
		{
			if (*num != '0')
				return (0);
			num++ ;
		}
		return (1);
	}
	return (0);
}

int	check_dup(int num, t_llist *lst)
{
	while (lst != NULL)
	{
		if (lst->data == num)
			return (0);
		else
			lst = lst->n;
	}
	return (1);
}

int	contains_digit_only(char *num)
{
	int	i;

	i = 0;
	if (num == NULL || num[0] == '\0')
		return (0);
	while (num[i] != '\0')
	{
		if (!ft_isdigit(num[i]) && !ft_isspace_or_sign(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_int(char *num, t_llist **lst)
{
	long	i;

	i = ft_atoi_long(num);
	if (zero_check(num) && check_dup((int)i, *lst))
		return (1);
	if (i == 0 || (i < INT_MIN || i > INT_MAX))
		return (0);
	else if (!check_dup((int)i, *lst))
		return (0);
	return (1);
}

int	is_valid(char *num, t_llist **lst)
{
	if (num == NULL)
		return (0);
	if (contains_digit_only(num) && valid_int(num, lst))
		return (1);
	return (0);
}
