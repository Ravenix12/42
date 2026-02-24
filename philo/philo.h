/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:16:40 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/24 16:00:43 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_params
{
	int	philo;
	int	die;
	int	eat;
	int	sleep;
	int	eatnum;
	int	*forks;
	int ready;
}	t_params;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_philo		*next;
	int			dead;
	t_params	*params;
}	t_philo;

int			validation(int argc, char **argv);

t_params	*init_params(char **argv);
t_philo		*init_philo(int n, t_params *params);

void		*start(void *job);

#endif