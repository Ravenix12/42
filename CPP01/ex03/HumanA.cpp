/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:12:38 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 13:24:22 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon): 
_name(name), _weapon(weapon)
{ }

HumanA::~HumanA()
{ }

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
