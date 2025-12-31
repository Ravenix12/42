/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:29:29 by smariapp          #+#    #+#             */
/*   Updated: 2025/12/31 19:47:40 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	open_file(char **argv, int io)
{
	int	fd;

	if (ft_strncmp(argv[1], "here_doc", 9) != 0 && io == 2)
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (ft_strncmp(argv[1], "here_doc", 9) == 0 && io == 2)
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (io == 1)
		fd = open(argv[1], O_RDONLY);
	return (fd);
}
