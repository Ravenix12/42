/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:20:32 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/02 21:35:40 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isnum(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	validation(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6 || !argv)
	{
		write(1, "Please follow this format: ./philo \
number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n", 140);
		return (0);
	}
	while (argv && argv[i])
	{
		if (!ft_isnum(argv[i]) || (argv[i][0] == '-') || \
ft_atoi(argv[i]) == -1 || ft_atoi(argv[1]) == 0)
		{
			write(1, "One or more invalid inputs\n", 27);
			return (0);
		}
		i++;
	}
	return (1);
}
