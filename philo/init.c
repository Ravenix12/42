/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:52:24 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/02 21:30:43 by smariapp         ###   ########.fr       */
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
	t_params	*par;
	int			i;

	i = 0;
	par = malloc(sizeof(t_params));
	par->philo = ft_atoi(argv[1]);
	par->die = ft_atoi(argv[2]);
	par->eat = ft_atoi(argv[3]);
	par->sleep = ft_atoi(argv[4]);
	par->forks = (pthread_mutex_t *)malloc(par->philo * sizeof(*par->forks));
	while (i < par->philo)
		pthread_mutex_init(&par->forks[i++], NULL);
	par->ready = 0;
	par->dead = 0;
	par->full = 0;
	pthread_mutex_init(&par->log, NULL);
	pthread_mutex_init(&par->full_m, NULL);
	pthread_mutex_init(&par->r_d_m, NULL);
	if (argv[5])
		par->eatnum = ft_atoi(argv[5]);
	else
		par->eatnum = -1;
	return (par);
}

int	assign(t_philo *philo, int i, t_params *params)
{
	int	code;

	philo->id = i;
	philo->params = params;
	philo->meals = 0;
	philo->last = get_time_in_ms();
	pthread_mutex_init(&philo->tlast, NULL);
	pthread_mutex_init(&philo->meal, NULL);
	code = pthread_create(&philo->thread, NULL, start, philo);
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
	i = 0;
	while (i < n)
	{
		if (assign(philo, i, params) != 0)
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
	return (params->start = get_time_in_ms(), params->ready = 1, head);
}
