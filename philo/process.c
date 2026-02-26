/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:41:51 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/26 16:42:14 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_think(t_philo* philo)
{
	w_log((get_time_in_ms() - philo->start), philo->id, S);
	usleep(philo->params->sleep);
	w_log((get_time_in_ms() - philo->start), philo->id, T);
}

void	eat(t_philo* philo)
{
	int	*forks;
	int l;
	int	r;

	forks = philo->params->forks;
	l = philo->id;
	r = philo->next->id;
	pthread_mutex_lock(&forks[l]);
	w_log((get_time_in_ms() - philo->start), philo->id, F);
	pthread_mutex_lock(&forks[r]);
	w_log((get_time_in_ms() - philo->start), philo->id, F);
	philo->last = get_time_in_ms();
	usleep(philo->params->eat);
	pthread_mutex_unlock(&forks[l]);
	pthread_mutex_unlock(&forks[r]);
	philo->meals += 1;
	sleep_think(philo);
}

void	*start(void *job)
{
	t_philo	*philo;

	philo = (t_philo *)job;
	while (1)
	{
		if (!philo->params->ready)
			continue;
		if (philo->params->dead)
			break ;
		else // add sleep for even
			eat(philo);
	}
}
