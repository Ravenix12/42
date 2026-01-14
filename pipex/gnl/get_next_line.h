/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:29:47 by smariapp          #+#    #+#             */
/*   Updated: 2026/01/14 14:47:50 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// GNL Functions
char	*ft_alloc(char *line, char *buf, int ix);
char	*ft_body(int fd, char **rem, char *buf, char *line);
char	*get_next_line(int fd);

// Utility Functions
void	ft_strcopy(char *src, char *dst, int count);
int		ft_strchrm(const char *s, char c);
char	*ft_allocate_rem(char *rem);
#endif
