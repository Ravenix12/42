/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:46:16 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/11 15:10:40 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(15);
	Fixed const d(1);

	Point i(a,b);
	Point j(a,a);
	Point k(c,a);
	Point pointA(b,c);
	Point pointB(d,d);

	std::cout << "PointA is inside: " << bsp(i,j,k,pointA) << std::endl;
	std::cout << "PointB is inside: " << bsp(i,j,k,pointB) << std::endl;
	//BSP is buggy check again
	return 0;
}