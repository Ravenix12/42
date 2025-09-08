/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:56:24 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/04 20:02:37 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error_exit(char *error, int fd, char *line, t_p *info)
{
	close(fd);
	if (line)
		free(line);
	get_next_line(fd, 1);
	if (info)
		free(info);
	write(2, error, ft_strlen(error));
	exit(1);
}

int	check_epc(t_p *info, char *line, int final)
{
	if (final && info->collectibles > 0 && info->player == 1 && info->exit == 1)
		return (1);
	else if (final)
		return (0);
	while (*line != '\n' && *line != '\0')
	{
		if (*line == 'E')
			info->exit += 1;
		else if (*line == 'P')
			info->player += 1;
		else if (*line == 'C')
			info->collectibles += 1;
		else if (*line == 'X')
			info->enemy += 1;
		else if (*line != '0' && *line != '1')
			return (0);
		line++;
	}
	if (info->exit > 1 || info->player > 1)
		return (0);
	return (1);
}

int	check_walls(char *line, int length)
{
	int	i;

	i = 0;
	if (nl(line) != length)
		return (0);
	while (line[i] != '\n' && *line != '\0')
	{
		if (line[i] == '1')
			i++;
		else
			break ;
	}
	if (line[i] == '\n' || line[i] == '\0')
		return (2);
	if (*line == '1' && (*(line + length - 1) == '1'))
		return (1);
	return (0);
}

t_p	*check_invalid(int fd)
{
	char	*line;
	t_p		*info;
	int		length;
	int		last;

	line = get_next_line(fd, 0);
	length = nl(line);
	if (check_walls(line, length) != 2 || length < 3)
		error_exit("Error\nInvalid Map - 70\n", fd, line, NULL);
	info = ft_calloc(1, sizeof(t_p));
	info->lines = 0;
	while (line != NULL)
	{
		last = check_walls(line, length);
		if (!last || !check_epc(info, line, 0))
			error_exit("Error\nInvalid Map - 78\n", fd, line, info);
		free(line);
		line = get_next_line(fd, 0);
		info->lines += 1;
	}
	if (last != 2 || !check_epc(info, "", 1))
		error_exit("Error\nInvalid Map - 84\n", fd, NULL, info);
	info->length = length;
	close(fd);
	return (info);
}
