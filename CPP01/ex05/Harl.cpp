/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:17:34 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 18:05:25 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

	void Harl::debug( void )
	{
		std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
	}
	void Harl::info( void )
	{
		std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
	}
	void Harl::warning( void )
	{
		std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";		
	}
	void Harl::error( void )
	{
		std::cout << "This is unacceptable! I want to speak to the manager now.\n";		
	}

	void Harl::complain( std::string level )
	{
		std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

		void (Harl::*functions[4])(void) = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
		};

		for (int i = 0; i < 4; i++)
		{
			if (!level.compare(lvl[i]))
			{
				(this->*functions[i])();
				return;
			}
		}
		std::cout << "Unknown. TREAD CAREFULLY...\n";
	}

	Harl::Harl(){}
	Harl::~Harl(){}
