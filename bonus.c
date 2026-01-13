/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:13:55 by smariapp          #+#    #+#             */
/*   Updated: 2026/01/13 21:07:03 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	*pipes_inbtw(int read, char **argv, char **envp, int start)
{
	int	len;
	int	p[2];
	int cpid;
	int status;

	len = ft_arrlen - 1;
	while (start < len)
	{
		if (pipe(p) == -1)
			exit(1);
		cpid = fork();
		if (cpid == 0)
		{
			close(p[0]);
			process1_5(prev_fd, p[1], argv[i], envp);
		}
		if (prev_fd != fd_in)
			close(prev_read);
		close(p[1]);
		prev_fd = p[0];
		waitpid(cpid, &status, 0);
        start++;
	}
	return (p);
}

int dw_pipes_bonus(int fd1, int fd2, char **argv, char **envp)
{
	int		cpid1;
	int		cpidlast;
	int		p[2];
	int		write[2];
	int		status1;
	int		status2;

	status1 = 0;
	status2 = 0;
	pipe(p);
	cpid1 = fork();
	if (cpid1 == 0)
		process1(p, argv[2], envp, fd1);
	waitpid(cpid1, &status1, 0);
	p = pipes_inbtw(p[0], argv, envp, 2);
	cpidlast = fork();
	if (cpidlast == 0)
		process2(p, argv[3], envp, fd2);
	close(p[0]);
	close(p[1]);
	waitpid(cpidlast, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}

int dw_pipes_hd(int fd2, char **argv, char **envp)
{
	int		cpid1;
	int		cpidlast;
	int		p[2];
	int		write[2];
	int		status1;
	int		status2;

	status1 = 0;
	status2 = 0;
	pipe(p);
	cpid1 = fork();
	if (cpid1 == 0)
		heredoc_proc(argv, envp, fd2, p);
	waitpid(cpid1, &status1, 0);
	p = pipes_inbtw(p[0], argv, envp, 3)
	cpidlast = fork();
	if (cpidlast == 0)
		process2(p, argv[3], envp, fd2);
	close(p[0]);
	close(p[1]);
	waitpid(cpidlast, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	ret;

	if (argc >= 5)
	{
		fd2 = open_file(argv, 2);
		if (fd2 < 0)
			no_space_for_exit(argv[argc - 1], 1);
		if (ft_strncmp(argv[1], "here_doc", 9) != 0)
			fd1 = open_file(argv, 1);
		else if (argc >= 6)
			break; //call here_doc
		else
			no_space_for_exit("insuffient arguments", 1);
		if (fd1 < 0)
		{
			perror(argv[1]);
			fd1 = open("/dev/null", O_RDONLY | O_CREAT);
		}
		ret = dwpipes(fd1, fd2, argv, envp);
		return (close(fd1), close(fd2), ret);
	}
	no_space_for_exit("insuffient arguments", 1);
}
