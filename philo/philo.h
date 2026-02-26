/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:16:40 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/26 14:48:26 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define F "has taken a fork"
# define E "is eating"
# define S "is sleeping"
# define T "is thinking"
# define D "dead"

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_params
{
	int				philo;
	int				die;
	int				eat;
	int				sleep;
	int				eatnum;
	pthread_mutex_t *forks;
	int 			ready;
	int				dead;
	int				full;
	pthread_t		monitor;
}	t_params;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	struct s_philo	*next;
	long long		start;
	long long		last;
	int				meals;
	t_params		*params;
}	t_philo;

int			validation(int argc, char **argv);

t_params	*init_params(char **argv);
t_philo		*init_philo(int n, t_params *params);
long		ft_atoi(const char *nptr);

void		*start(void *job);
void		*monitor(void *job);

long long 	get_time_in_ms(void);
void		exit_condition(t_philo *philo);
void		w_log(long long time, int id, char *message);


#endif