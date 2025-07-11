/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   REMOVE.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:08:43 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/25 16:48:54 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "limits.h"

int main(void)
{
	//unsigned int MAX = 4294967295;
	//ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", '9', "Hello", (void *)3, 123, INT_MIN, MAX, 123, 123);
	//printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", '9', "Hello", (void *)3, 123, INT_MIN, MAX, 123, 123);
	printf("%d\n",ft_printf("abcde"));
	printf("%d",printf("abcde"));
}
