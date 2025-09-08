/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:09:00 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/06 21:31:17 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_player(char **arr, t_p *info)
{
	free_arr(arr);
	if (info)
		free(info);
}

void	malloc_exit(char **arr, t_p *info)
{
	free_player(arr, info);
	write(2, "Error\nMalloc Failure\n", 21);
	exit(1);
}

char	**save_map(int fd, t_p *info)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc((1 + info->lines) * sizeof(char *));
	if (map == NULL)
		malloc_exit(NULL, info);
	while (i < info->lines)
	{
		map[i] = get_next_line(fd, 0);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	*find_coordinates(char **map, char c, t_p *info)
{
	int	i;
	int	j;
	int	*coor;

	i = 0;
	coor = (int *)malloc(2 * sizeof(int));
	if (!coor)
		malloc_exit(NULL, info);
	while (i < info->lines)
	{
		j = 0;
		while (j < info->length)
		{
			if (map[i][j] == c)
			{
				coor[0] = i;
				coor[1] = j;
				return (coor);
			}
			j++;
		}
		i++;
	}
	free(coor);
	return (NULL);
}

char	**duplicate_map(char **map, t_p *info)
{
	char	**dup;
	int		i;

	i = 0;
	dup = (char **)malloc((1 + info->lines) * sizeof(char *));
	if (dup == NULL)
		malloc_exit(NULL, info);
	while (i < info->lines)
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
		{
			free(dup);
			malloc_exit(map, info);
		}
		i++;
	}
	dup[info->lines] = NULL;
	return (dup);
}
