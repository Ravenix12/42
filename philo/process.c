/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:41:51 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/02 21:37:38 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_think(t_philo *philo)
{
	t_params	*params;

	params = philo->params;
	w_log((get_time_in_ms() - params->start), philo->id, S, philo->params);
	ft_usleep(philo->params->sleep, philo->params);
	w_log((get_time_in_ms() - params->start), philo->id, T, philo->params);
	usleep(500);
}

//everyone picks up lower fork first
void	get_forks(t_philo *philo, pthread_mutex_t *forks)
{
	int				l;
	int				r;
	t_params		*params;

	params = philo->params;
	l = philo->id;
	r = philo->next->id;
	if (l > r)
	{
		pthread_mutex_lock(&forks[r]);
		w_log((get_time_in_ms() - philo->params->start), l, F, philo->params);
		pthread_mutex_lock(&forks[l]);
	}
	else
	{
		pthread_mutex_lock(&forks[l]);
		w_log((get_time_in_ms() - params->start), l, F, params);
		pthread_mutex_lock(&forks[r]);
	}
	w_log((get_time_in_ms() - params->start), l, F, params);
	pthread_mutex_lock(&philo->tlast);
	philo->last = get_time_in_ms();
	pthread_mutex_unlock(&philo->tlast);
}

void	eat(t_philo *philo)
{
	pthread_mutex_t	*frks;
	int				l;
	int				r;
	t_params		*params;

	params = philo->params;
	frks = philo->params->forks;
	l = philo->id;
	r = philo->next->id;
	get_forks(philo, frks);
	pthread_mutex_lock(&philo->params->r_d_m);
	if (philo->params->dead)
		return (pthread_mutex_unlock(&frks[l]), pthread_mutex_unlock(&frks[r]), \
pthread_mutex_unlock(&philo->params->r_d_m), (void)0);
	pthread_mutex_unlock(&philo->params->r_d_m);
	w_log((get_time_in_ms() - params->start), l, E, params);
	ft_usleep(philo->params->eat, philo->params);
	pthread_mutex_unlock(&frks[l]);
	pthread_mutex_unlock(&frks[r]);
	pthread_mutex_lock(&philo->meal);
	philo->meals += 1;
	pthread_mutex_unlock(&philo->meal);
	sleep_think(philo);
}

void	single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->forks[0]);
	w_log(0, philo->id, F, philo->params);
	ft_usleep(philo->params->die, philo->params);
	philo->params->dead = 1;
}

void	*start(void *job)
{
	t_philo	*philo;

	philo = (t_philo *)job;
	//pthread_mutex_lock(&philo->params->r_d_m);
	while (!philo->params->ready)
		usleep(100);
	//pthread_mutex_unlock(&philo->params->r_d_m);
	if (philo->next == philo)
		return (single_philo(philo), NULL);
	pthread_mutex_lock(&philo->tlast);
	philo->last = philo->params->start;
	pthread_mutex_unlock(&philo->tlast);
	if (philo->id % 2 == 0)
		usleep(philo->params->eat * 400);
	while (1)
	{
		pthread_mutex_lock(&philo->params->full_m);
		pthread_mutex_lock(&philo->params->r_d_m);
		if (philo->params->dead || philo->params->full)
			return (NULL);
		pthread_mutex_unlock(&philo->params->full_m);
		pthread_mutex_lock(&philo->params->r_d_m);
		eat(philo);
	}
	return (NULL);
}
