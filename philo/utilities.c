/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 21:16:23 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/03 18:34:33 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long ms, t_params *params)
{
	long long	start;
	int			dead;

	start = get_time_in_ms();
	while (1)
	{
		pthread_mutex_lock(&params->r_d_m);
		dead = params->dead;
		pthread_mutex_unlock(&params->r_d_m);
		if (dead)
			break ;
		if (get_time_in_ms() - start >= ms)
			break ;
		usleep(1000);
	}
}

long long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	exit_condition(t_philo *philo)
{
	t_philo	*head;
	t_philo	*prev;

	head = philo;
	philo = philo->next;
	while (philo != head)
	{
		prev = philo;
		pthread_join(prev->thread, NULL);
		philo = prev->next;
		free(prev);
	}
	pthread_join(head->params->monitor, NULL);
	pthread_join(head->thread, NULL);
	free(head->params->forks);
	free(head->params);
	free(head);
}

void	w_log(long long time, int id, char *message, t_params *params)
{
	long long	now;
	int			dead;

	now = time - gs_start(params, 1);
	pthread_mutex_lock(&params->r_d_m);
	dead = params->dead;
	pthread_mutex_unlock(&params->r_d_m);
	pthread_mutex_lock(&params->log);
	if (!dead || message[0] == 'd')
		printf("%d %d %s\n", (int)now, id, message);
	pthread_mutex_unlock(&params->log);
}
