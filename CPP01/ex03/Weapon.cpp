/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:12:18 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 15:13:42 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string Weapon::getType()
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

Weapon::Weapon()
{ }

Weapon::Weapon(std::string type): _type(type)
{ }

Weapon::~Weapon()
{ }

