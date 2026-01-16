/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:35:08 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/29 15:45:43 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fdnode
{
	int					fd;
	char				*rem;
	struct s_fdnode		*next;
}				t_fdnode;
// GNL
char		*ft_allocate_rem(char *rem);
char		*ft_alloc(char *line, char *buf, int ix);
char		*ft_body(int fd, char **rem, char *buf, char *line);
char		*ft_line(t_fdnode *n, int fd, t_fdnode **fd_lst, char *buf);
char		*get_next_line(int fd);
// Utilies
t_fdnode	*get_fdnode(int fd, t_fdnode **head);
void		free_fdnode(int fd, t_fdnode **head);
void		ft_strcopy(char *src, char *dst, int count);
size_t		ft_strlen(const char *s);
int			ft_strchrm(const char *s, char c);
#endif
