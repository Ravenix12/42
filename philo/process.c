/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:41:51 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/24 22:10:30 by smariapp         ###   ########.fr       */
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

void	eat(t_philo* philo)
{
	int	*forks;
	int l;
	int	r;

	forks = philo->params->forks;
	l = philo->id;
	r = philo->next->id;	
	pthread_mutex_lock(forks[l]);
	pthread_mutex_lock(forks[r]);
	philo->last = get_time_in_ms();
	
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
		else // add sleep for even 
			routine();
	}
}
