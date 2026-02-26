/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 21:16:23 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/26 14:44:48 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_time_in_ms(void)
{
    struct timeval	tv;

    gettimeofday(&tv, NULL);    
    return ((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void	exit_condition(t_philo *philo)
{
	t_philo *head;
	t_philo *prev;

	head = philo;
	philo = philo->next;
	while(philo != head)
	{
		prev = philo;
		philo = prev->next;
		free(prev);
	}
	free(head->params->forks);
	free(head->params);
	free(head);
}

void	w_log(long long time, int id, char *message)
{
	ft_putnbr_fd((int)time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(id, 1);
	write(1, " ", 1);
	write(1, message, ft_strlen(message));
}