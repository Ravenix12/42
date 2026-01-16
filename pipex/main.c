/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:17:42 by smariapp          #+#    #+#             */
/*   Updated: 2026/01/14 21:21:41 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	ret;

	if (argc == 5)
	{
		fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd2 < 0)
			no_space_for_exit(argv[argc - 1], 1);
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 < 0)
		{
			perror(argv[1]);
			fd1 = open("/dev/null", O_RDONLY);
		}
		ret = dwpipes(fd1, fd2, argv, envp);
		close(fd1);
		close(fd2);
		return (ret);
	}
	return (1);
}
