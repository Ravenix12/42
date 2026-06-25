/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:12:32 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 13:26:10 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):
_name(name)
{ }

HumanB::~HumanB()
{ }

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}