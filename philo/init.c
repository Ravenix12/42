/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:52:24 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/03 19:48:46 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

t_params	*init_params(char **argv)
{
	t_params	*par;
	int			i;

	i = 0;
	par = ft_calloc(sizeof(t_params), 1);
	par->philo = ft_atoi(argv[1]);
	par->die = ft_atoi(argv[2]);
	par->eat = ft_atoi(argv[3]);
	par->sleep = ft_atoi(argv[4]);
	par->forks = (pthread_mutex_t *)malloc(par->philo * sizeof(*par->forks));
	while (i < par->philo)
		pthread_mutex_init(&par->forks[i++], NULL);
	par->think = (par->die - par->eat - par->sleep) / 2;
	if (par->think < 0)
		par->think = 0;
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
	return (gs_start(params, 0), pthread_mutex_lock(&params->r_d_m), \
params->ready = 1, pthread_mutex_unlock(&params->r_d_m), head);
}
