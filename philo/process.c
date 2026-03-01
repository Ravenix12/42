/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:41:51 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/01 21:27:21 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_think(t_philo *philo)
{
	t_params *params;

	params = philo->params;
	w_log((get_time_in_ms() - params->start), philo->id, S, philo->params);
	usleep(philo->params->sleep * 1000);
	w_log((get_time_in_ms() - params->start), philo->id, T, philo->params);
}

//everyone picks up lower fork first
void	get_forks(t_philo *philo, pthread_mutex_t *forks)
{
	int				l;
	int				r;
	t_params 		*params;
	
	params = philo->params;
	l = philo->id;
	r = philo->next->id;
	if (l > r)
	{
		pthread_mutex_lock(&forks[r]);
		w_log((get_time_in_ms() - philo->params->start), r, F, philo->params);
		pthread_mutex_lock(&forks[l]);
		w_log((get_time_in_ms() - params->start), l, F, params);
	}
	else
	{
		pthread_mutex_lock(&forks[l]);
		w_log((get_time_in_ms() - params->start), l, F, params);
		pthread_mutex_lock(&forks[r]);
		w_log((get_time_in_ms() - params->start), r, F, params);
	}
	pthread_mutex_lock(&philo->meal_last);
	philo->last = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_last);
}

void	eat(t_philo *philo)
{
	pthread_mutex_t	*forks;
	int				l;
	int				r;
	t_params 		*params;
	
	params = philo->params;
	forks = philo->params->forks;
	l = philo->id;
	r = philo->next->id;
	get_forks(philo, forks);
	if (philo->params->dead)
	{
		pthread_mutex_unlock(&forks[l]);
		pthread_mutex_unlock(&forks[r]);
		return;
	}
	w_log((get_time_in_ms() - params->start), l, E, params);
	usleep(philo->params->eat * 1000);
	pthread_mutex_unlock(&forks[l]);
	pthread_mutex_unlock(&forks[r]);
	pthread_mutex_lock(&philo->meal_last);
	philo->meals += 1;
	pthread_mutex_unlock(&philo->meal_last);
	sleep_think(philo);
}

void	single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->forks[0]);
	w_log(0, philo->id, F, philo->params);
	usleep(philo->params->die * 1000);
	philo->params->dead = 1;
}

void	*start(void *job)
{
	t_philo	*philo;

	philo = (t_philo *)job;
	if (philo->next == philo)
		return(single_philo(philo), NULL);
	while (!philo->params->ready)
		;
	pthread_mutex_lock(&philo->meal_last);
    philo->last = philo->params->start;
    pthread_mutex_unlock(&philo->meal_last);
	if (philo->id % 2 == 0)
		usleep(800);
	while (1)
	{
		if (philo->params->dead || philo->params->full)
			return (NULL);
		eat(philo);
	}
	return (NULL);
}
