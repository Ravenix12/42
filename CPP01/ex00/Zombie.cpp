/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 09:53:12 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 11:17:28 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zName): name(zName)
{ 
	std::cout << "Zombie " << name << " created\n";
}

Zombie::Zombie( void )
{ }

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " destroyed\n";
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
