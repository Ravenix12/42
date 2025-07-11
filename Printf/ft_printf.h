/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:12:54 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/25 16:32:39 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>

// helper functions
int				ft_digits(unsigned int n, int base);
int				ft_digits_ul(unsigned long n, int base);
int				ft_pow(unsigned int num, int exp);
unsigned long	ft_pow_ul(unsigned long num, int exp);

// main functions
int				ft_printf(const char *str, ...);
int				ft_putchari_fd(int c, int fd, const char **s);
int				ft_puthex_fd(unsigned int n, int fd, char c, const char **s);
int				ft_puthexl_fd(unsigned int n, int fd);
int				ft_puthexu_fd(unsigned int n, int fd);
int				ft_puthexul_fd(unsigned long n, int fd, const char **s);
int				ft_putnbri_fd(int n, int fd, const char **s);
int				ft_putstd_fd(char *s, int fd, const char **str);
int				ft_putstri_fd(char *s, int fd, const char **sfd);
int				ft_putuint_fd(unsigned int n, int fd, const char **s);

#endif