/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:10:28 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/25 16:37:01 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		c;

	c = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%' && str[1] == 'c' )
			c += ft_putchari_fd(va_arg(args, int), 1, &str);
		else if (*str == '%' && str[1] == 's' )
			c += ft_putstri_fd(va_arg(args, char *), 1, &str);
		else if (*str == '%' && (str[1] == 'd' || str[1] == 'i'))
			c += ft_putnbri_fd(va_arg(args, int), 1, &str);
		else if (*str == '%' && str[1] == 'u')
			c += ft_putuint_fd(va_arg(args, unsigned int), 1, &str);
		else if (*str == '%' && (str[1] == 'x' || str[1] == 'X'))
			c += ft_puthex_fd(va_arg(args, unsigned int), 1, str[1], &str);
		else if (*str == '%' && str[1] == 'p')
			c += ft_puthexul_fd((unsigned long)va_arg(args, void *), 1, &str);
		else
			c += ft_putstd_fd((char *)str, 1, &str);
	}
	return (c);
}
