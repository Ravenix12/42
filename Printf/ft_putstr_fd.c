/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:00:01 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/24 20:54:58 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstri_fd(char *s, int fd, const char **str)
{
	(*str) += 2;
	if (s)
		write(fd, s, ft_strlen(s));
	else
		return (write(fd, "(null)", 6));
	return (ft_strlen(s));
}
