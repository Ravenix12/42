/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:26:56 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/06 20:07:34 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_close(t_par *params)
{
	free_display(params->data, params->display);
	free_player(params->map, params->info);
	free(params);
	exit(0);
	return (0);
}

int	handle_inputs(t_par *params)
{
	mlx_hook(params->data->win, DestroyNotify, StructureNotifyMask,
		&ft_close, params);
	mlx_hook(params->data->win, KeyPress, KeyPressMask, &ft_keypress, params);
	return (0);
}

t_par	*set_param(char **map, t_p *info, t_data *data, t_dis *dis)
{
	t_par	*params;

	params = ft_calloc(1, sizeof(t_par));
	if (!params)
		malloc_fail(map, info, data, dis);
	params->data = data;
	params->display = dis;
	params->map = map;
	params->info = info;
	return (params);
}

void	config_display(t_p *info, t_data *data)
{
	int	screenx;
	int	screeny;
	int	x;
	int	y;

	mlx_get_screen_size(data->mlx, &screenx, &screeny);
	if (screenx > info->length * 64)
		x = info->length;
	else
		x = screenx / 64;
	if (screenx > info->lines * 64)
		y = info->lines;
	else
		y = screeny / 64;
	data->win = mlx_new_window(data->mlx, x * 64, y * 64, "So_long");
	info->dx = x;
	info->dy = y;
}

void	lib_entry(char **map, t_p *info)
{
	t_data	data;
	t_dis	*display;
	t_par	*params;

	data.mlx = mlx_init();
	if (!data.mlx)
		malloc_exit(map, info);
	config_display(info, &data);
	if (!data.win)
	{
		free(data.mlx);
		malloc_exit(map, info);
	}
	display = ft_calloc(1, sizeof(t_dis));
	if (!display)
		malloc_fail(map, info, &data, display);
	init_pics(display, map, info, &data);
	params = set_param(map, info, &data, display);
	mlx_loop_hook(data.mlx, &display_screen, params);
	handle_inputs(params);
	mlx_loop(data.mlx);
}
