/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:41:51 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/03 19:49:09 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_think(t_philo *philo)
{
	t_params	*params;

	params = philo->params;
	w_log(get_time_in_ms(), philo->id, S, params);
	ft_usleep(philo->params->sleep, params);
	w_log(get_time_in_ms(), philo->id, T, params);
	ft_usleep(philo->params->think, philo->params);
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
	if (l % 2)
	{
		pthread_mutex_lock(&forks[r]);
		w_log(get_time_in_ms(), l, F, params);
		pthread_mutex_lock(&forks[l]);
	}
	else
	{
		pthread_mutex_lock(&forks[l]);
		w_log(get_time_in_ms(), l, F, params);
		pthread_mutex_lock(&forks[r]);
	}
	w_log(get_time_in_ms(), l, F, params);
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
	w_log(get_time_in_ms(), l, E, params);
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
	pthread_mutex_lock(&philo->params->log);
	printf("%d %d %s\n", 0, philo->id, F);
	pthread_mutex_unlock(&philo->params->log);
	ft_usleep(philo->params->die, philo->params);
	pthread_mutex_unlock(&philo->params->forks[0]);
	pthread_mutex_lock(&philo->params->r_d_m);
	philo->params->dead = 1;
	pthread_mutex_unlock(&philo->params->r_d_m);
}

void	*start(void *job)
{
	t_philo	*philo;

	philo = (t_philo *)job;
	wait_ready(philo->params);
	if (philo->next == philo)
		return (single_philo(philo), NULL);
	pthread_mutex_lock(&philo->tlast);
	philo->last = gs_start(philo->params, 1);
	pthread_mutex_unlock(&philo->tlast);
	if (philo->id % 2 == 0)
		usleep(philo->params->eat * 700);
	while (1)
	{
		pthread_mutex_lock(&philo->params->r_d_m);
		pthread_mutex_lock(&philo->params->full_m);
		if (philo->params->dead || philo->params->full)
			return (pthread_mutex_unlock(&philo->params->full_m), \
pthread_mutex_unlock(&philo->params->r_d_m), NULL);
		pthread_mutex_unlock(&philo->params->full_m);
		pthread_mutex_unlock(&philo->params->r_d_m);
		eat(philo);
	}
	return (NULL);
}
