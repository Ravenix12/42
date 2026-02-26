

#include "philo.h"

void	*monitor(void *job)
{
	t_philo	*philos;
	int 	i;

	philos = (t_philo *)job;
	i = 0;
	while (1)
	{
		while (!philos->params->ready)
			break; //check this later
		while (i < philos->params->philo)
		{
			if (get_time_in_ms() - philos->last > philos->params->die)
				philos->params->die = 1;
			i++;
		}
		i = 0;
		while (i < philos->params->philo)
		{
			if (philos->params->eatnum < philos->meals)
				break;
			i++;
		}
		if (i == (philos->params->philo - 1))
			philos->params->full = 1;
	}
}

