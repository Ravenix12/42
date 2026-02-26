/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:52:24 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/26 14:48:51 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + *nptr - '0';
		if (result > 2147483647)
			return (-1);
		nptr++;
	}
	return (sign * result);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, nmemb * size);
	return (ptr);
}

//forks: setting to 0-> 0 means available
t_params	*init_params(char **argv)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	params->philo = ft_atoi(argv[1]);
	params->die = ft_atoi(argv[2]);
	params->eat = ft_atoi(argv[3]);
	params->sleep = ft_atoi(argv[4]);
	params->forks = (pthread_mutex_t *)ft_calloc(params->philo, sizeof(*params->forks));
	params->ready = 0;
	params->dead = 0;
	if (argv[5])
		params->eatnum = ft_atoi(argv[5]);
	else
		params->eatnum = -1;
	return (params);
}

int	assign(t_philo *philo, int i, t_params *params, long long time)
{
	int code;

	code = pthread_create(&philo->thread, NULL, start, philo);
	philo->id = i;
	philo->params = params;
	philo->start = time;
	philo->last = time;
	philo->meals = 0;
	return (code);
}

t_philo	*init_philo(int n, t_params *params)
{
	t_philo			*philo;
	t_philo			*prev;
	t_philo			*head;
	int				i;

	philo = malloc(sizeof(t_philo));
	head = philo;
	while (i < n)
	{
		if (assign(philo, i, params, get_time_in_ms()) != 0)
			exit_condition(head);
		prev = philo;
		if (i < n - 1)
		{
			philo = malloc(sizeof(t_philo));
			prev->next = philo;
		}
		else
			prev->next = head;
		i++;
	}
	pthread_create(&params->monitor, NULL, monitor, head);
	return (params->ready = 1, head);
}
