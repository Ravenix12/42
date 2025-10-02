/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kinda_like_libft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:41:52 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/14 18:28:29 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace_or_sign(char c)
{
	if ((c >= 9 && c <= 13) || c == '-' || c == '+')
		return (1);
	return (0);
}

long	ft_atoi_long(const char *nptr)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (ft_strncmp(nptr, "-2147483648", 12) == 0)
		return (-2147483648);
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + *nptr - '0';
		if ((result * sign) > (long)INT_MAX || (result * sign) < (long)INT_MIN)
			return ((long)INT_MAX + 2);
		nptr++;
	}
	if (*nptr != '\0')
		return (0);
	return (sign * result);
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
