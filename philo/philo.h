/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:16:40 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/18 20:46:18 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_params
{
	int	philo;
	int	die;
	int	eat;
	int	sleep;
	int	eatnum;
}	t_params;

typedef struct s_philo
{
	pthread_t	thread;
	t_philo		*next;
} t_philo;

int			validation(int argc, char **argv);

t_params	*init_params(char **argv);
t_philo		*init_philo(int n);

void		*start(void);


#endif