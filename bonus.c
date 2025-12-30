/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:13:55 by smariapp          #+#    #+#             */
/*   Updated: 2025/12/30 22:02:11 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	ret;

	if (argc >= 5)
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
	else
		no_space_for_exit("insuffient arguments", 1)
}
