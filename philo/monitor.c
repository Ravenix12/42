/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:17:02 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/02 21:38:19 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_or_alive(t_philo *philos)
{
	int			i;
	t_params	*params;
	long long	last;

	params = philos->params;
	i = 0;
	while (i < params->philo)
	{
		pthread_mutex_lock(&philos->tlast);
		last = philos->last;
		pthread_mutex_unlock(&philos->tlast);
		if (get_time_in_ms() - last > params->die)
		{
			pthread_mutex_lock(&philos->params->r_d_m);
			params->dead = 1;
			pthread_mutex_unlock(&philos->params->r_d_m);
			w_log(get_time_in_ms() - params->start, philos->id, D, params);
			return (-1);
		}
		philos = philos->next;
		i++;
	}
	return (1);
}

int	are_they_full(t_philo *philos)
{
	int	i;
	int	meals;

	i = 0;
	while (i < philos->params->philo)
	{
		pthread_mutex_lock(&philos->meal);
		meals = philos->meals;
		pthread_mutex_unlock(&philos->meal);
		if (meals < philos->params->eatnum)
			break ;
		philos = philos->next;
		i++;
	}
	if (i == philos->params->philo)
	{
		pthread_mutex_lock(&philos->params->full_m);
		philos->params->full = 1;
		pthread_mutex_unlock(&philos->params->full_m);
		return (0);
	}
	return (1);
}

void	*monitor(void *job)
{
	t_philo	*philos;
	t_philo	*head;
	int		i;

	head = (t_philo *)job;
	//pthread_mutex_lock(&head->params->r_d_m);
	while (!head->params->ready)
		usleep(100);
	//pthread_mutex_lock(&head->params->r_d_m);
	while (1)
	{
		philos = head;
		i = 0;
		if (dead_or_alive(philos) == -1)
			return (NULL);
		if (head->params->eatnum != -1)
		{
			if (!are_they_full(philos))
				return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
