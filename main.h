/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:58:54 by smariapp          #+#    #+#             */
/*   Updated: 2025/12/30 20:27:12 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "Libft/libft.h"
#include "gnl/get_next_line.h"

// Utility functions
char	**get_paths(void);
char	*path_constructor(char *arr);
void	no_space_for_exit(char *statement, int status);
void	free_arr(char **arr);
void	write_for_me(int writefd, int readfd);

// Main functions
int		helper_free(char **args, char *argv, char *path, int ret);
void	process1(int pipefds[2], char *argv, char **envp, int fd1);
void	process2(int pipefds[2], char *argv, char **envp, int fd2);
int		dwpipes(int fd1, int fd2, char **argv, char **envp);
int		main(int argc, char **argv, char **envp);

#endif