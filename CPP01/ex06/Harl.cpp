/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:17:34 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/30 20:42:08 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i;
	for (i = 0; i < 4; i++)
	{
		if (!level.compare(lvl[i]))
		{
			break;
		}
	}

	switch(i) {
	case 0:
		std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";
	case 1:
		std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
	case 2:
		std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n\n";
	case 3:
		std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n\n";
		break;
	default:	
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
Harl::Harl() {}
Harl::~Harl() {}
