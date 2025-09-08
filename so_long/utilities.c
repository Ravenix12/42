/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:05:48 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/06 21:42:16 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	nl(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++ ;
	return (len);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	counter(int num)
{
	char	*str;

	write(1, "Number of Movements: ", 21);
	str = ft_itoa(num);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

void	put_counter(t_par *params)
{
	char	*num;

	num = ft_itoa(params->info->movements);
	mlx_string_put(params->data->mlx, params->data->win, 20, 20, 0, "Counter ");
	mlx_string_put(params->data->mlx, params->data->win, 90, 20, 0, num);
	free(num);
}
