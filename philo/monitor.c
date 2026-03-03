/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:17:02 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/03 11:40:46 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_ready(t_params *params)
{
	while (1)
	{
		pthread_mutex_lock(&params->r_d_m);
		if (params->ready)
		{
			pthread_mutex_unlock(&params->r_d_m);
			break ;
		}
		pthread_mutex_unlock(&params->r_d_m);
		usleep(100);
	}
}

//get: 1, set: 0
long long	gs_start(t_params *params, int gs)
{
	long long	start;

	if (gs)
	{
		pthread_mutex_lock(&params->start_m);
		start = params->start;
		pthread_mutex_unlock(&params->start_m);
		return (start);
	}
	else
	{
		pthread_mutex_lock(&params->start_m);
		params->start = get_time_in_ms();
		pthread_mutex_unlock(&params->start_m);
		return (0);
	}
}

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
			w_log(get_time_in_ms(), philos->id, D, params);
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

	head = (t_philo *)job;
	wait_ready(head->params);
	while (1)
	{
		philos = head;
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
