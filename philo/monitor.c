/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:17:02 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/01 20:42:08 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int dead_or_alive(t_philo *philos)
{
	int i;
	t_params *params;
	long long last;

	params = philos->params;
	i = 0;
	while (i < params->philo)
	{
		pthread_mutex_lock(&philos->meal_last);
		last = philos->last;
		pthread_mutex_unlock(&philos->meal_last);
		if (get_time_in_ms() - last > params->die)
		{
			params->dead = 1;
			w_log(get_time_in_ms() - params->start, philos->id, D, params);
			return (-1);
		}
		philos = philos->next;
		i++;
	}
	return (1);
}

int are_they_full(t_philo *philos)
{
	int i;
	int meals;

	i = 0;
	while (i < philos->params->philo)
	{
		pthread_mutex_lock(&philos->meal_last);
		meals = philos->meals;
		pthread_mutex_unlock(&philos->meal_last);
		if (meals < philos->params->eatnum)
			break;
		philos = philos->next;
		i++;
	}
	return (i);
}

void *monitor(void *job)
{
	t_philo *philos;
	t_philo *head;
	int i;

	head = (t_philo *)job;
	while (!head->params->ready)
		;
	while (1)
	{
		philos = head;
		i = 0;
		if (dead_or_alive(philos) == -1)
			return (NULL);
		if (head->params->eatnum != -1)
		{
			i = are_they_full(philos);
			if (i == philos->params->philo)
				return (philos->params->full = 1, NULL);
		}
	}
	return (NULL);
}
