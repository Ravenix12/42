/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:29:26 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/25 16:34:13 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digits(unsigned int n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n /= base;
		count += 1;
	}
	return (count);
}

int	ft_pow(unsigned int num, int exp)
{
	int	base;

	base = num;
	while (exp > 1)
	{
		num *= base;
		exp--;
	}
	if (exp == 0)
		num = 1;
	return (num);
}

unsigned long	ft_pow_ul(unsigned long num, int exp)
{
	unsigned long	base;

	base = num;
	while (exp > 1)
	{
		num *= base;
		exp--;
	}
	if (exp == 0)
		num = 1;
	return (num);
}

int	ft_putuint_fd(unsigned int n, int fd, const char **s)
{
	int				digits;
	unsigned int	num;
	char			temp[1];
	unsigned int	divisor;
	int				count;

	(*s) += 2;
	digits = ft_digits(n, 10);
	count = 0;
	while (digits > 0)
	{
		divisor = ft_pow(10, digits - 1);
		num = n / divisor;
		temp[0] = num + '0';
		count += write (fd, temp, 1);
		n %= divisor;
		digits --;
	}
	return (count);
}

/* #include <stdio.h>
int main()
{
	ft_putnbr_fd(-2147483648, 1);
} */