/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:02:42 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/15 12:18:35 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap player1 = ClapTrap("player1");
	ClapTrap player2 = ClapTrap("player2");

	//player 1 attacks player 2
	player1.attack("player2");
	player2.takeDamage(0);

	//player 2 atatcks player 1
	player2.attack("player1");
	player1.takeDamage(0);

	//display final player stats
	std::cout << player1.getName() << std::endl;
	std::cout << player1.getAttackPoints() << std::endl;
	std::cout << player1.getEnergyPoints() << std::endl;
	std::cout << player1.getHitPoints() << std::endl;

	std::cout << player2.getName() << std::endl;
	std::cout << player2.getAttackPoints() << std::endl;
	std::cout << player2.getEnergyPoints() << std::endl;
	std::cout << player2.getHitPoints() << std::endl;
}