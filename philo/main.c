/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:59:59 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/18 20:46:24 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_params	*params;
	t_philo		*philo;

	if (!validation(argc, argv))
		return (0);
	params = init_params(argv);
	philo = init_philo(params->philo);
	return (0);
}
