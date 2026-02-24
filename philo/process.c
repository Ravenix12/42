/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:41:51 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/24 16:10:26 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead(t_philo *philosophers)
{
	int	n;
	int	i;

	n = philosophers->params->philo;
	while (i < n)
	{
		if (philosophers->dead)
			return (1);
		philosophers = philosophers->next;
		i++;
	}
	return (0);
}

void	*start(void *job)
{
	t_philo	*philos;

	philos = (t_philo *)job;
	while (1)
	{
		if (!philos->params->ready)
			continue;
		if (dead(philos))
			break ;
		else
			routine();
	}
}
